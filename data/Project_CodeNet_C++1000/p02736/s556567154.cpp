#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int Solve(vector<int>& a)
{
    if (count(a.begin(), a.end(), 0) == a.size())
        return 0;
    int n = a.size();
    vector<int> fact(n);
    for (int i = 2; i < n; i += 2)
        fact[i] = fact[i / 2] + 1;
    partial_sum(fact.begin(), fact.end(), fact.begin());
    bool odd = false;
    for (int i = 0; i < n; ++i)
        if (fact[n - 1] - fact[n - 1 - i] - fact[i] == 0 && a[i] % 2)
            odd ^= 1;
    if (odd)
        return 1;
    else if (count(a.begin(), a.end(), 1))
        return 0;
    else {
        for (int& i: a)
            if (i) i = 1;
        return Solve(a) ? 2 : 0;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    string b;
    cin >> b;
    vector<int> a(n - 1);
    for (int i = 0; i < n - 1; ++i)
        a[i] = abs(b[i + 1] - b[i]);
    cout << Solve(a);
}
