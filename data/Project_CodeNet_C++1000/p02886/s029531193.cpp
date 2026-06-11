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
    int n; cin >> n;
    V<int> d(n);
    for(int i = 0; i < n; i++) cin >> d[i];

    int sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            sum += d[i] * d[j];
        }
    }

    cout << sum << endl;
    return 0;
}
