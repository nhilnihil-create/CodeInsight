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
int main(){
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    vector<ll> v(n);
    rep(i,n) cin >> v[i];
    vector<ll> m(n,0);
    rep(i,n){
        if(i%2 == 0) m[0] += v[i];
        else m[0] -= v[i];
    }
    for(int  i = 1; i < n; i++){
        m[i] = 2*v[i-1] - m[i-1];
    }
    rep(i,n) cout << m[i] << endl;
    return 0;
}