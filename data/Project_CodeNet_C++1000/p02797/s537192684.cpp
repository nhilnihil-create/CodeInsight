#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int main(){
    cout << fixed << setprecision(10);
    ll n,k,s;
    cin >> n >> k >> s;
    vector<int> v(n);
    rep(i,n){
        if(i < k) v[i] = s;
        else if(s < 1e9) v[i] = s + 1;
        else v[i] = s - 1;
    }
    rep(i,n) cout << v[i] << endl;
    return 0;
}