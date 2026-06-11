/*#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")*/
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define Str(x) to_string(x)
#define len(s) (int)s.size()

typedef long long ll;
typedef long double lld;
typedef string str;
typedef unsigned long long ull;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    multiset <int> a, b;
    n = (1 << n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.insert(-x);
    }
    int val = *a.begin();
    a.erase(a.find(val));
    b.insert(-val);
    int k = 1;
    for (int i = 1; i < n * 2; i ++)
    {
        if (a.empty())
            break;
        vector <int> flex;
        for (auto it : b)
        {
            auto f = a.upper_bound(-it);
            if (f == a.end())
            {
                cout << "No";
                return 0;
            }
            flex.pb(*f);
            a.erase(a.find(*f));
        }
        for (auto it : flex)
            b.insert(-it);
        k *= 2;
    }
    cout << "Yes";

    return 0;
}