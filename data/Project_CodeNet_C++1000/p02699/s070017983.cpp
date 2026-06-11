#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    ll s,w;
    cin >> s >> w;
    if (w >= s){cout << "unsafe" << endl;}
    else {cout << "safe" << endl;}
    return 0;
}
