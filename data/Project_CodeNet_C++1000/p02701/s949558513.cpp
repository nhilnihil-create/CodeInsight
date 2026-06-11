#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
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
const long long INF = 1LL << 60;

int main()
{
    ll n;
    int cnt;
    map<string, int> m;
    cin >> n;
    string str;
    vector<string> s;
    for (ll i = 0; i < n; i++)
    {
        cnt = 0;
        cin >> str;
        m[str] = 1;
    }

    cout << m.size() << endl;
    return 0;
}
