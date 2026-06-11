#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using Graph = vector<vector<int>>;

int main(){
    int N; cin>>N;
    vector<ll> A(N);
    rep(i,N)cin>>A.at(i);
    sort(A.begin(),A.end());
    reverse(A.begin(),A.end());
    ll res = A.at(0);
    ll cnt = N-2;
    // cnt is even
    rep1(i,(N-2)/2)res += A.at(i)*2;
    if(cnt%2==1)res += A.at(cnt/2+1);
    cout<<res<<endl;
}