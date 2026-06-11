#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i,a,n) for(ll i=a;i<(ll)(n);i++)

int main(){
    long a,b,x; cin>>a>>b>>x;

    double ans;
    if(x >= a*a*b/2){
        double c = (double)x/(a*a);
        ans = atan(((double)b-c)/(a/2.0));
        ans *= 180/M_PI;
    }else{
        double c = (2.0*x)/(a*b);
        ans = atan(c/b);
        ans *= 180/M_PI;
        ans = 90 - ans;
    }

    cout << fixed << setprecision(10) << ans << endl;
}
