#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define RREP(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//const ll INF = 1LL << 60;
//const int INF = 1001001001;

int main(void){
    double a,b,x;
    cin >> a >> b >> x;
    double ans;
    double V=a*a*b;
    if(x>V/2)
        ans=atan((b-x/a/a)/(a/2))*180.0/M_PI;
    else 
        ans=atan(b/(2*x/a/b))*180.0/M_PI;
        
    printf("%.7f\n",ans);
        return 0;
}