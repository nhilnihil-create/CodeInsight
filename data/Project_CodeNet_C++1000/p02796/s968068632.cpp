#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    //input
    long long N;
    cin >> N;
    vector<pair<long long,long long> > start;
    vector<pair<long long,long long> > goal;
    long long X,L;
    long long i,j;
    for(i=0; i<N; i++){
        cin >> X >> L;
        start.push_back(make_pair(X-L,i));
        goal.push_back(make_pair(X+L,i));
    }

    //calc
    sort(start.begin(),start.end());
    sort(goal.begin(),goal.end());
    bool usable[N];
    fill(usable,usable+N,1);
    long long ans=0;
    long long j_sta=0;
    for(i=0; i<N; i++){
        if(usable[goal[i].second]){
            ans++;
            usable[goal[i].second]=0;
            for(j=j_sta; j<start.size(); j++){
                if(start[j].first<goal[i].first){
                    usable[start[j].second]=0;
                }else{
                    break;
                }
            }
            j_sta=j;
        }
    }

    //answer
    cout << ans << endl;
    system("pause");
    return 0;
}