#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;
#define fast() ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define digit(N) cout << fixed << setprecision((N))

int N, M, P;

int main()
{
    while (cin >> N >> M >> P)
    {
        if (N == 0 && M == 0 && P == 0)
            return 0;
        int sum = 0, people = 0;
        vector<int> a(N);
        for (int i = 0; i < N; i++)
        {
            cin >> a[i];
            sum += a[i] * 100;
            people += a[i];
        }
        if (a[M - 1] == 0)
        {
            cout << 0 << "\n";
        }
        else
        {
            sum -= sum * P / 100;
            cout << sum / a[M - 1] << "\n";
        }
    }
}
