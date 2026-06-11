#include <bits/stdc++.h>
#define ll long long
#define pb(x) push_back((x))
#define line() cerr << "DEBUG @" << __LINE__ << endl;
#define debug(x) \
    cerr << "DEBUG @" << __LINE__ << " -> " << #x << " = " << x << endl;
using namespace std;

vector<int> m[(int) 1e6 + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &x : v) cin >> x;
    const int mx = 1e6;
    vector<int> divisors(mx + 1);
    for (int i = 2; i <= 1000000; i++) {
        if (!divisors[i]) {
            for (int j = i; j <= 1000000; j += i) {
                divisors[j] = i;
            }
        }
    }
    bool pair_wise_coprime = true;
    bool gcd_is_one = true;

    for (int x : v) {
        int cur = x;
        set<int> q;
        while (cur != 1) {
            q.insert(divisors[cur]);
            cur /= divisors[cur];
        }
        for (int div : q) {
            auto &curr_map = m[div];
            curr_map.push_back(x);
            if (curr_map.size() > 1) pair_wise_coprime = false;
            if (curr_map.size() == n) gcd_is_one = false;
        }
    }
    if (pair_wise_coprime) {
        cout << "pairwise coprime\n";
        return 0;
    }
    if (gcd_is_one) {
        cout << "setwise coprime\n";
        return 0;
    }
    cout << "not coprime\n";
}
