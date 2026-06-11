#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long
#define mod 1000000007
#define IINF INT_MAX
#define INF 1LL << 30


int main() {
    int n, d; cin >> n >> d;
    V<V<int> > v(n, V<int>(d));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < d; j++){
            cin >> v[i][j];
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int sq = 0;
            for(int k = 0; k < d; k++){
                int s = v[i][k] - v[j][k];
                sq += s * s;
            }
            // 小数点切り捨てで1.99999...が2なのに1になる対策
            int s = sqrt(sq) + 0.5;
            if(s * s == sq) ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
