#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>           // sorted map so O(logn)
#include <unordered_map> // O(1)
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main()
{
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        a[i] = k;
    }
    for (int i = 0; i < q; ++i)
    {
        int x;
        cin >> x;
        a[x - 1]++;
    }
    for (int i = 0; i < n; ++i)
    {
        a[i] -= q;
        if (a[i] > 0)
        {
            cout << "Yes"
                 << " ";
        }
        else
        {
            cout << "No"
                 << " ";
        }
    }
}