#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;


int main() {
    double a,b,x,ans;
    cin >> a >> b >> x;
    if(x < a*a*b/2){
        ans = atan(a*b*b/2/x);
    } else ans = atan(2*(a*a*b-x)/a/a/a);

    double pi = acos(-1.0);
    ans = ans * 180 / pi;
    cout << fixed << setprecision(11) << ans << endl;
}
