#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    // input
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    // count
    vector<ll> cnt(N + 1, 0);
    for (ll v : A)
        cnt[v] += 1;
    sort(cnt.begin(), cnt.end());

    vector<ll> cumsum(N + 1);
    cumsum[0] = 0;
    for (int i = 1; i <= N; i++)
        cumsum[i] = cumsum[i - 1] + cnt[i];

    vector<ll> times(N + 1);
    for (int i = 1; i <= N; i++)
    {
        int ng = upper_bound(cnt.begin(), cnt.end(), i) - cnt.begin();
        times[i] = (cumsum[ng - 1] + (N - ng + 1) * i) / i;
    }

    for (int k = 1; k <= N; k++)
    {
        int ok = 0, ng = N + 1, mid;
        while (ng - ok > 1)
        {
            mid = (ok + ng) / 2;
            if (times[mid] >= k)
                ok = mid;
            else
                ng = mid;
        }
        cout << ok << endl;
    }

    return 0;
}
