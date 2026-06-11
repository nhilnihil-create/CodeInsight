#include <bits/stdc++.h>

typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
#define repr(i, n) for (ll i = n - 1; i >= 0; --i)
#define INF 10e8
#define MOD 1000000000 + 7
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))
using namespace std;

void solve(void)
{
    int n;
    cin >> n;
    vector<int> tmp;
    rep(i, n) tmp.push_back(i + 1);
    vector<int> A(n), B(n);
    rep(i, n) cin >> A[i];
    rep(i, n) cin >> B[i];
    int a, b, cta = 1;
    do
    {
        if (tmp == A)
            a = cta;
        if (tmp == B)
            b = cta;
        cta++;
    } while (next_permutation(all(tmp)));
    cout << abs(a - b) << endl;
}
int main(void)
{
    solve();
}