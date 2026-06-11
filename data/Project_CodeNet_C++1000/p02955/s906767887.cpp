#include <bits/stdc++.h>
#define rep(a,n) for (int a = 0; a < (n); ++a)
using namespace std;
using ll = long long;
typedef pair<ll,ll> P;
typedef pair<P,ll> PP;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;


//input
ll n,k;
vector<ll>a;

/*  divisor(n)
    入力：整数 n
    出力：nのすべての約数
    計算量：O(√n)
*/
vector<ll>divisor(ll n){
    vector<ll>ret;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            ret.push_back(i);
            if(i*i!=n)ret.push_back(n/i);
        }
    }
    sort(ret.begin(),ret.end());
    return ret;
}

bool solve(ll x){
    vector<ll>rem;
    rep(i,n){
        rem.push_back(a[i]%x);
    }
    ll s = accumulate(rem.begin(),rem.end(),0);
    if(s%x!=0)return false;
    sort(rem.begin(),rem.end());
    ll res = 0;
    rep(i,n-s/x){
        res += rem[i];
    }
    if(res<=k)return true;
    else return false;
}

int main(){
    cin >> n >> k;
    a.resize(n);
    rep(i,n)cin>>a[i];
    ll S = accumulate(a.begin(),a.end(),0);
    auto div = divisor(S);
    reverse(div.begin(),div.end());
    rep(i,div.size()){
        if(solve(div[i])){
            cout << div[i] << endl;
            return  0;
        }

    }

    return 0;
}
