#include<iostream>
#include<queue>
#include<string>

using namespace std;

int main(){
    int n, q;
    queue< pair<string, int> > Q;
    string tmp_name;
    int tmp_time;

    cin >> n >> q;

    for(int i=0; i<n; i++){
        cin >> tmp_name >> tmp_time;
        Q.push(make_pair(tmp_name, tmp_time));
    }
    
    pair<string, int> tmp;
    int ans=0;

    while(!Q.empty()){
        tmp = Q.front();
        Q.pop();
        tmp_time = tmp.second;
        if(tmp_time<=q){
            ans += tmp_time;
            cout << tmp.first << " "<< ans << endl;
        }else{
            ans += q;
            Q.push(make_pair(tmp.first, tmp_time-q));
            
        }
    }
    return 0;
}