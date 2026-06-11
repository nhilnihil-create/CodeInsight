#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef pair<int, int> pii;
typedef complex<double> xy_t;

double dot(xy_t a, xy_t b){
    return (conj(a) * b).real();
}

int main(){
    int n;
    scanf("%d", &n);
    xy_t p[n];
    rep(i, n){
        double x, y;
        scanf("%lf%lf", &x, &y);
        p[i] = xy_t(x, y);
    }
    
    double ans = 0;
    rep(t, 100000){
        xy_t a = xy_t(cos(t), sin(t));
        xy_t z = xy_t(0, 0);
        rep(i, n)if(dot(a, p[i]) >= 0){
            z += p[i];
        }
        ans = max(ans, abs(z));
    }
    
    printf("%.12lf\n", ans);
}