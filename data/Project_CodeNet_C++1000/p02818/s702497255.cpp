#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    ll taka,aoki,k;
    cin >> taka >> aoki >> k;
    ll ans1, ans2;
    ll temp1 = taka, temp2 = aoki;
    taka = taka - k;
    if (taka <= 0){ans1 = 0; }else{ ans1 = taka;}
    if (k <= taka){ans2 = aoki;} else { ll rem = k - temp1; aoki = aoki - rem; if (aoki <= 0){ans2 = 0;} else {ans2 = aoki;}}
    cout << ans1 << " " << ans2 << endl;
    return 0;
}
