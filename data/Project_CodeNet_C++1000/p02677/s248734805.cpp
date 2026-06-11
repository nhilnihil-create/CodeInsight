#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep2(i,x,n) for (int i = x; i < n; i++)
using ll = long long int;
int main() {
    long double pi = 3.14159265358979323846264338327950;
    int a,b,h,m; cin >> a >> b >> h >> m;
    long double rad = pi*2.0*(
        (long double)h/12.0+((long double)m/60.0)/12.0
            -(long double)m/60.0);
    long double raq = (long double)(a*a+b*b)
        -(long double)(2.0*a*b)*cosl(rad);
    cout << fixed << setprecision(20) << sqrtl(raq) << endl;
    return 0;
}