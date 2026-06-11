#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using Graph = vector<vector<int>>;

int main(){
    int K; cin>>K;
    int res = 1;
    int S = 7;
    if(K%2==0){
        cout<<-1<<endl;
        return 0;
    }
    while(S%K!=0){
        S = S*10 + 7;
        res++;
        S%=K;
        if(res>K+10){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<res<<endl;
}