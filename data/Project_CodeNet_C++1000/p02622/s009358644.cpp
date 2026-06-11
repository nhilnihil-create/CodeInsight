#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using Graph = vector<vector<int>>;

int main(){
    string S,T; cin>>S>>T;
    int res = 0;
    for(int i = 0; i < S.size(); i++)if(S[i]!=T[i])res++;
    cout<<res<<endl;
}