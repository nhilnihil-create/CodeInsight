#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
long long inf = pow(10, 9);

int n, a[81];
int main(){
    cin >> n;
    rep(i, n) cin >> a[i];
    long long res = 1000;
    rep(i, n - 1){
        if(a[i] < a[i + 1]) res += (res / a[i]) * (a[i + 1] - a[i]);
    }
    cout << res << endl;
}