#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;
const int N = 2e5 + 5;

int main()
{
    int n;
    cin >> n;
    vector<int> t(n + 1);
    vector<int> h(n);
    ll s = 0;
    rep(i, n + 1)
    {
        cin >> t[i];
        s += t[i];
    }
    rep(i, n)
    {
        cin >> h[i];
    }
    ll tt = s;
    rep(i, n)
    {
        if (h[i] > t[i])
        {
            s -= t[i];
            h[i] -= t[i];
            t[i] = 0;
            if (h[i] > t[i + 1])
            {
                s -= t[i + 1];
                t[i + 1] = 0;
            }
            else
            {
                t[i + 1] -= h[i];
                s -= h[i];
            }
        }
        else
        {
            s -= h[i];
            t[i] -= h[i];
        }
    }
    cout << (tt - s) << endl;
}