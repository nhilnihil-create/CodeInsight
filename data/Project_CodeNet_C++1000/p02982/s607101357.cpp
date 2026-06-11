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
    V<V<int> > v(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < d; j++){
            int x; cin >> x;
            v[i].push_back(x);
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            double sum = 0;
            for(int k = 0; k < d; k++){
                sum += pow(abs(v[i][k] - v[j][k]), 2);
            }
            if(floor(sqrt(sum)) == sqrt(sum)) ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
