#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
static const int INFTY = (1 << 30);
int N, K, R, S, P;
void func()
{
    cin >> N >> K;
    cin >> R >> S >> P;
    string T;
    cin >> T;
    int ans(0), max(0), v[N];
    rep(i, 0, N)
    {
        if (T[i] == 'r')
        {
            max += P;
            v[i] = 3;
        }
        else if (T[i] == 's')
        {
            max += R;
            v[i] = 1;
        }
        else
        {
            max += S;
            v[i] = 2;
        }
    }
    rep(i, K, N)
    {
        if (v[i] == v[i - K])
        {
            v[i] == 1 ? max -= R : v[i] == 2 ? max -= S : max -= P;
            v[i] = 0;
        }
    }
    cout << max << endl;
}
int main()
{
    func();
}