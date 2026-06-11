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
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    for (int i = 0; i < h; i++)
    {
        if (i < b)
        {
            for (int j = 0; j < a; j++)
            {
                cout << 0;
            }
            for (int j = a; j < w; j++)
            {
                cout << 1;
            }
            cout << endl;
        }
        else
        {
            for (int j = 0; j < a; j++)
            {
                cout << 1;
            }
            for (int j = a; j < w; j++)
            {
                cout << 0;
            }
            cout << endl;
        }
    }
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