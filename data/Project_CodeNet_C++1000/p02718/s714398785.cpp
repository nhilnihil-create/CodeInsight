#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;


int main() {
    int n, m; cin >> n >> m;
    V<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int s = accumulate(ALL(a), 0);

    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(a[i] * 4 * m >= s) cnt++;
        if(cnt == m){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;



    return 0;
}
