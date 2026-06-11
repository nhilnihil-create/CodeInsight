#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=0;(i)<(n);i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define MOD 1000000007
#define FOUT(n, dist) cout<<fixed<<setprecision(n)<<(dist);
#define BR cout<<endl;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define ALL(v) v.begin(), v.end()
typedef long long ll;
const ll mod=1000000007;

ll powmod(ll x,ll y){
    ll res=1;
    for(ll i=0;i<y;i++){
        res=res*x%mod;
    }
    return res;
}

double expect(int x){
    double kitai,tem=0;
    for(int i=1;i<=x;i++){
        tem += i;
    }
    kitai = tem/x;
    cout << kitai << endl;
    return kitai;
    
}

int main(){
    int n;cin >> n;
    int k;cin >> k;
    double p[n];rep(i,n) cin >> p[i];

    double q[n];
    rep(i,n)q[i] = (p[i]+1)/2;

    double c[n];
    rep(i,n)c[i] = 0;
    rep(i,n)c[i + 1] = c[i] + q[i];

    double ans =0;
    rep(i, n){
        if(i + k >= n + 1)break;
        chmax(ans, c[i + k] - c[i]);
    }

    FOUT(12, ans)BR;


    return 0;
}

