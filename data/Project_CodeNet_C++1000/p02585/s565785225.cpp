#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    vector<ll> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i]--;
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    ll res = -LINF;
    for (int i = 0; i < n; ++i) {
        int index = i;
        ll sum = 0;
        int size = 0;
        while(1){
            index = p[index];
            sum += c[index];
            size++;
            if (index == i) break;
        }

        index = i;
        ll sum_rem = 0;
        for (int j = 0; j < size; ++j) {
            if (j == k) break;

            index = p[index];
            sum_rem += c[index];
            res = max(res, sum_rem + (k - j - 1) / size * max(0LL, sum));
        }
    }
    cout << res << endl;
}