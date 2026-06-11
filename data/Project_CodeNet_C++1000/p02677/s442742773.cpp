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
const ll INF = 1LL << 60;


int main(void){
    long double a,b,h,m;
    cin >> a >> b >> h >> m;
    long double a2=a*a,b2=b*b,rad=abs(6*m-(30*h+0.5*m))*M_PI/180;
    long double cosrad=cos(rad);
    long double c=a2+b2-2*a*b*cosrad;
    c=sqrt(c);
    printf("%.11LF\n",c);

    return 0;
}