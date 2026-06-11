#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1001001001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int main()
{
    // 割引額のリストを作成してソートする
    int n, m;
    cin >> n >> m;
    priority_queue<ll> mq;
    ll total = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        total += a;
        while (a != 0)
        {
            int af = a / 2;
            mq.push(a - af);
            a /= 2;
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (mq.empty())
        {
            break;
        }
        total -= mq.top();
        mq.pop();
    }
    cout << total << endl;
    return 0;
}

// Use For Debug
template <typename T>
void print(T const &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
};