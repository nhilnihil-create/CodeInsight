#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define LB(a,x) lb(all(a),x)-a.begin()
#define UB(a,x) ub(all(a),x)-a.begin()
#define mod 1000000007
//#define mod 998244353
#define FS fixed<<setprecision(15)
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline void out(T a){ cout << a << '\n'; }
void YN(bool ok){if(ok) cout << "Yes" << endl; else cout << "No" << endl;}
//void YN(bool ok){if(ok) cout << "YES" << endl; else cout << "NO" << endl;}


const ll INF=1e18;
const int mx=200005;

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    int n;
    cin>>n;
    V<int> a(n);
    cinf(n,a);
    V<int> s(1000001);
    V<bool> p(1000001,1);
    for(int i=2;i<=1000000;i++){
        if(p[i]){
            s[i]=i;
            for(int j=2*i;j<=1000000;j+=i){
                p[j]=0;
                s[j]=i;
            }
        }
    }
    V<int> cnt(1000001,0);
    rep(i,n){
        int cur=a[i];
        int div=s[a[i]];
        while(cur>1){
            while(cur%div==0) cur/=div;
            cnt[div]++;
            div=s[cur];
        }
    }
    bool ok=1;
    int g=a[0];
    for(int i=1;i<n;i++) g=__gcd(g,a[i]);
    for(int i=2;i<=1000000;i++){
        if(cnt[i]>1){
            ok=0;
        }
    }
    if(ok) out("pairwise coprime");
    else if(g==1) out("setwise coprime");
    else out("not coprime");
}