#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define arr array

using namespace std;

const int e = 2e6 + 69;
const ll mod = 1e9 + 7;

ll a[e], b[e];

//beginner 1999 129


int main()
{
     int a, b, c;
     cin >> a >> b >> c;
     cout << min(min(a+b, a+c), b+c);
}
