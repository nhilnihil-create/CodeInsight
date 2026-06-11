#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double db;

#define endl "\n"

const int MOD = 1000000007;


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    string s, t;
    cin >> s >> t;
    int a = t.size();
    string x = t.substr(0,a-1);
    if(x == s)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
	return 0;
}
