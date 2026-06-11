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
    int a, b;
    cin >> a >> b;
    string aa, bb;
    if (a < b)
    {
        for (int i = 0; i < b; i++)
        {
            cout << a;
        }
        cout << endl;
    }
    else
    {
        for (int i = 0; i < a; i++)
        {
            cout << b;
        }
        cout << endl;
    }
}