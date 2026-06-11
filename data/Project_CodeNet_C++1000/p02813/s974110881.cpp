#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int N;
    cin>>N;

    vector<int> P(N);
    for(int i=0; i<N; i++){
        cin>>P[i];
    }

    vector<int> Q(N);
    for(int i=0; i<N; i++){
        cin>>Q[i];
    }

    vector<int> v(N);
    //1刻みで格納できる関数
    iota(v.begin(), v.end(), 1);

    ll P_cnt = 0;
    ll Q_cnt = 0;
    bool P_flag = false;
    bool Q_flag = false;

    do{
        if(v == P){
            P_flag = true;
        }
        if(v == Q){
            Q_flag = true;
        }

        if(!P_flag){
            P_cnt++;
        }
        if(!Q_flag){
            Q_cnt++;
        }

        if(P_flag && Q_flag){
            break;
        }
    }while(next_permutation(v.begin(), v.end()));

    cout<<abs(P_cnt - Q_cnt)<<endl;
    return 0;
}