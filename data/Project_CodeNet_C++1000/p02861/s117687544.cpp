#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define m0(x) memset(x, 0, sizeof(x))
#define all(x) x.begin(), x.end()
#define rep(i, n) for(int i = 0; i < (n); i++)
#define asort(x) sort(all(x));
#define dsort(x, t) sort(x.begin(), x.end(), greater<t>());
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());
#define MINS(m, s) m.insert(make_pair(s, 1));
#define MFIN(m, s) m.find(s) != m.end()
const int mod = 1000000007;

int factorialMethod(int k) {
    int sum = 1;
    for(int i = 1; i <= k; ++i) {
        sum *= i;
    }
    return sum;
}

int main() {
    int n;
    int x[10], y[10];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    vector<int> v;
    for(int i = 0; i < n; i++) {
        v.push_back(i);
    }

    int factor = factorialMethod(n);
    double ave = 0.0;
    for(int i = 0; i < factor; i++) {
        for(int j = 0; j < n - 1; j++) {
            ave += sqrt(pow(x[v[j]] - x[v[j + 1]], 2) +
                        pow(y[v[j]] - y[v[j + 1]], 2));
        }
        next_permutation(v.begin(), v.end());
    }
    printf("%.10f\n", (double)ave / factor);
    return 0;
}