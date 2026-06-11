#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    ll a ;
    double b;
    cin >> a >> b;
    ll c = b * 100 + 0.001;
    ll ans = a * c ;
    ans /= 100;
    cout << ans << endl;

    return 0;
}
