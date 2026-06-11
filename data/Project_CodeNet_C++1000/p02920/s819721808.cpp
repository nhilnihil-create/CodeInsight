#include <bits/stdc++.h>
#define INF 1e18
#define int long long
#define Rep(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) Rep(i, 0, n)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;
const int mod = 1000000007;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int N = pow(2, n);
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    sort(all(a));
    reverse(all(a));
    a.push_back(-1);
    vector<int> v;
    int cnt = 1;
    rep(i, N)
    {
        if (a[i] == a[i + 1])
            cnt++;
        else
        {
            v.push_back(cnt);
            cnt = 1;
        }
    }
    priority_queue<int> que;
    que.push(2 * N - 1);
    rep(i, v.size())
    {
        if (que.size() < v[i])
        {
            cout << "No" << endl;
            return 0;
        }
        vector<int> w;
        rep(j, v[i])
        {
            int tmp = que.top();
            que.pop();
            w.push_back(tmp);
        }
        rep(j, v[i])
        {
            while (w[j] / 2 > 0)
            {
                que.push(w[j] / 2);
                w[j] /= 2;
            }
        }
    }
    cout << "Yes" << endl;
}