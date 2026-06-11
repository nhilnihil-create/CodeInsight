/*
ID: alec3
LANG: C++14
PROG:
*/

#include <bits/stdc++.h>

#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ss second
#define ff first
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ld long double
#define all(c) (c).begin(), (c).end()
#define FOR(i, a, b) for (int i = a; i < b; i++)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int pct(int x) { return __builtin_popcount(x); }
bool absComp (int i, int j) { return (abs(i) < abs(j)); }


int main()
{
    io;
    int n;
    cin >>n;
    string s = to_string(n);
    char digit = s[s.size() -1];

    if (digit == '2' || digit == '4' || digit == '5' || digit == '7' || digit == '9')
        cout << "hon" << endl;
    else if (digit == '3')
        cout << "bon" << endl;
    else
        cout << "pon" << endl;


    return 0;
}
