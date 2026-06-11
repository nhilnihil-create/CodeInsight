#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()
    
using namespace std;
using ll = long long;
using pii = pair<int, int>;
    
const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const double PI = acos(-1);

long double f(long double& x){
    return ((x*(x+1))/2.0)/x;
}

int main(){
    cout << fixed << setprecision(10);
    int n, k;
    cin >> n >> k;

    vector <long double> v(n), ps(n+1, 0.0);

    for (auto& x: v) cin >> x, x = f(x);


    long double ans = -1.0;
    for (int i=1; i<=n; i++){
        ps[i] = ps[i-1] + v[i-1];
        if (i >= k) ans = max(ans, ps[i] - ps[i-k]);
    }


    cout << ans << endl;
    return 0;
}