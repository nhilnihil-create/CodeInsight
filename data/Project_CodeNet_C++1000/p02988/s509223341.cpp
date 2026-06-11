#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
const ll INF = 1LL << 60;

int main()
{

    int n;
    cin >> n;
    int p[n];
    rep(i,n){
        cin >> p[i];
    }

    int ans = 0;
    rep(i, n - 2){
        if ((p[i] > p[i+1])&&(p[i+1] > p[i+2]))
        {
                ans += 1;
        }
        if ((p[i] < p[i + 1]) && (p[i + 1] < p[i + 2]))
        {
            ans += 1;
        }
    }

    cout << ans << endl;

    return 0;
}
