#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define ll long long

int main(){
    double a,b,h,m;
    cin >> a >> b >> h >> m;
    double H1,W1,H2,W2;
    long double ans;
    H1=a*cos(2*M_PI/12*(double)(h+m/60));
    W1=a*sin(2*M_PI/12*(double)(h+m/60));
    H2=b*cos(2*M_PI/60*m);
    W2=b*sin(2*M_PI/60*m);
    ans=sqrt(abs(H1-H2)*abs(H1-H2)+abs(W1-W2)*abs(W1-W2));
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}