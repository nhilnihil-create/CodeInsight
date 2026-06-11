#include <bits/stdc++.h>
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
#define FS fixed<<setprecision(15)
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<n;i++)
const double pi=3.141592653589793;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const ll INF=1e18;

int main(){
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++){
        string s=to_string(i);
        if(s.size()%2==1) ans++;
    }
    cout<<ans<<endl;
}
