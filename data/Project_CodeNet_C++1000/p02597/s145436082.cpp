#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using Graph = vector<vector<int>>;

int main(){
    int N;cin>>N;
    string S;cin>>S;
    vector<int> R(N,0),W(N,0);
    rep(i,N){
        if(S.at(i)=='R')R.at(i)++;
        else W.at(i)++;
        if(i!=0){
            R.at(i)+=R.at(i-1);
            W.at(i)+=W.at(i-1);
        }
    }
    int res = 0;
    if(R.at(N-1)==0||W.at(N-1)==0){
        cout<<0<<endl;
        return 0;
    }
    rep(i,N){
        if(W.at(i)>R.at(N-1)-R.at(i))continue;
        res = max(res,W.at(i));
    }
    cout<<res<<endl;
}