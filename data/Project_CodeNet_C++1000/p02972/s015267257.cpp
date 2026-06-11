#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5, mod = 1e9 + 7;
int n, a[N], b[N];

int main()
{
    //ios::sync_with_stdio(false);cin.tie(nullptr);ios_base::sync_with_stdio(false);
    cin >> n;
    vector<int> v;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = n; i > 0; i--)
    {
        int c = 0;
        for (int j = i + i; j <= n; j += i)
            c += b[j];
        if (c % 2 != a[i] % 2)
            v.push_back(i),
            b[i] = 1;
    }
    cout << v.size() << endl;
    sort(v.begin(), v.end());
    for (auto it: v)
        cout << it << ' ';
    return 0;
}