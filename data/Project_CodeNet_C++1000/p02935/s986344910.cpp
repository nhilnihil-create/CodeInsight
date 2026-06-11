#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX;
const ll MINF = LLONG_MIN;
const int INT_INF = INT_MAX;

int main()
{
    int n;
    cin >> n;
    vector<double> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    double res = 0.0;
    for (int i = 1; i < n; i++)
    {
        v[i] = (v[i - 1] + v[i]) / 2.0;
    }
    cout << v[n - 1] << endl;
}