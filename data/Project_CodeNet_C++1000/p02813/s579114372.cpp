#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define reps(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; --i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define repc2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define inf 2e9
#define linf 9000000000000000000ll
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int n;

int main() {
    cin >> n;
    vector<int> v1(n), v2(n), sorted;
    rep(i, n) cin >> v1[i];
    rep(i, n) cin >> v2[i];
    sorted = v1;
    sort(all(sorted));
    int a = 0, b = 0;
    do {
        a++;
    } while (next_permutation(all(v1)));
    do {
        b++;
    } while (next_permutation(all(v2)));
    cout << abs(a - b) << endl;
    return 0;
}