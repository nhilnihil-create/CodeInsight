#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    sp(10);
    double a,b;cin>>a>>b;
    double h,m;cin>>h>>m;
    double x=6*m,y=30*h+0.5*m;
    double buf=abs(x-y);
    double pi=acos(-1);
    buf*=pi/180;
    double res=a*a+b*b-2*a*b*cos(buf);
    //cout<<x<<" "<<y<<endl;
    res=sqrt(res);
    cout<<res<<endl;
}