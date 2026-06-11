#include <bits/stdc++.h>
using namespace std;
//
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mx 100010
#define pi acos(-1)
#define endl '\n'
#define Fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
//
int main()
{
    ll n, x;
    string s, s1, s2;

    cin >> n;
    cin >> s;

    if (n % 2 == 1)
    {
        cout << "No" << endl;
    }
    else
    {
        x = n / 2;
        s1 = s.substr(0, x);
        s2 = s.substr(x, n);

        if (s1 == s2)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}
