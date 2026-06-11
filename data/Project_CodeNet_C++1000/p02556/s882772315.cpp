#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
long mod = (long) 1e9 + 7;

long MAX(long x, long y){
    if(x > y){
        return x;
    } else {
        return y;
    }
}

long MIN(long x, long y){
    if(x < y){
        return x;
    } else {
        return x;
    }
}

int main(){
    
    long n, xmin, xmax, ymin, ymax, ans;
    cin >> n;
    vector<long> x(n,0), y(n,0), z(n,0), w(n,0);
    rep(i,n) cin >> x[i] >> y[i];
    
    xmin = x[0];
    xmax = x[0];
    ymin = y[0];
    ymax = y[0];
    rep(i,n){
        xmin = MIN(xmin, x[i]);
        xmax = MAX(xmax, x[i]);
        ymin = MIN(ymin, y[i]);
        ymax = MAX(ymax, y[i]);
    }

    rep(i,n) z[i] = x[i] - xmin + y[i] - ymin;
    rep(i,n) w[i] = x[i] - xmin + ymax - y[i];
    sort(z.begin(), z.end());
    sort(w.begin(), w.end());

    ans = MAX((z[n-1] - z[0]), (w[n-1] - w[0]));

    cout << ans << "\n";
    
    return 0;
}

