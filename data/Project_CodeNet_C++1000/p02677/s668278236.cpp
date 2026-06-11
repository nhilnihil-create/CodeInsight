#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=(n);i++)
#define PI 3.1415926535897932384626433832795028841971693993
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;

int main(){
    long double a,b,h,m;
    cin>>a>>b>>h>>m;
    long double ang=2*PI*(h/12.0+m/12.0/60.0-m/60.0);
    long double ans=(a*a+b*b)-(2*a*b*cosl(ang));
    ans=sqrtl(ans);
    printf("%20.20Lf",ans);
}