/*The woods are lovely, dark and deep,
But I have promises to keep,
And miles to go before I sleep,
And miles to go before I sleep.*/

//PRABHJOT SINGH A.K.A. PRABHI
//~~~~~conquizztador~~~~~


#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
const int MOD = 1000000007;
const int MOD1 = 998244353;
const int maxn = 100010;
const int lim = (int)1e9;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x = 0;
	cin >> x;
	if (x >= 400 && x < 600)
		cout << "8";
	else if (x >= 600 && x < 800)
		cout << "7";
	else if (x >= 800 && x < 1000)
		cout << "6";
	else if (x >= 1000 && x < 1200)
		cout << "5";
	else if (x >= 1200 && x < 1400)
		cout << "4";
	else if (x >= 1400 && x < 1600)
		cout << "3";
	else if (x >= 1600 && x < 1800)
		cout << "2";
	else
		cout << "1";
	cout << endl;
}