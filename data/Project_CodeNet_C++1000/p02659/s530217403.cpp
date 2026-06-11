#include<bits/stdc++.h>

using namespace std;

#define TC ll t; cin >> t; while(t--)
typedef long long ll;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    long long a,bb;
    double b;
    cin >> a >> b;
    bb=round(b*100);
    cout << (a*bb)/100 << endl;
    return 0;
}
