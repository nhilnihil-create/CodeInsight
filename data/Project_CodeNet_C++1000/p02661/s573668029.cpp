#include <bits/stdc++.h>
using namespace std;
using f32 = float;
using f64 = double;
using LL = long long;
using ULL = unsigned long long;
#define REP(i, n) for (LL i = 0; i < (int)(n); i++)
#define FOR(i, m, n) for (LL i = m; i < n; i++)
#define SORT(x) sort(x.begin(), x.end())
#define REVE(x) reverse(x.begin(), x.end())
#define all(x) (x).begin(), (x).end()

signed main()
{
    long long N;
  cin >> N;
    vector<long long> a(N);
    vector<long long> b(N);
    REP(i, N){
        cin >> a[i] >> b[i];
    }
    SORT(a);
    SORT(b);
    if (N % 2 == 0) {
        long long mi = a[N/2-1] + a[N/2];
        long long ma = b[N/2-1] + b[N/2];
        cout << ma - mi + 1 << endl;
    } else {
        long long mi = a[N/2], ma = b[N/2];
        cout << ma - mi + 1 << endl;
    }
}
