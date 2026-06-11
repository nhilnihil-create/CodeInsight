#include<bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using pint = pair<int,int>;
using pll = pair<ll,ll>;
using Graph = vector<vector<int>>;

int K;
void solve(vector<ll> &A,ll now){
    if(now>3234566667){
        return;
    }

    A.push_back(now);
    if(now%10!=0) solve(A,now*10+now%10-1);
    solve(A,now*10+now%10);
    if(now%10!=9) solve(A,now*10+now%10+1);
}

int main(){
    cin>>K;
    vector<ll> res;
    rep1(i,9){
        solve(res,i);
    }
    sort(res.begin(),res.end());
    
    cout<<res[K-1]<<endl;
}
