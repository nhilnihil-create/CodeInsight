#include<iostream>
#include<map>
#include<algorithm>
#include<cmath>
#define ll long long
#define rep(i, n) for(i=0; i<n; i++)
#define rep1(i, n) for(i=1; i<=n; i++)
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, k, q;
	cin >> n >> k >> q;
	map<ll, ll> player;
	int i;
	/*ll players[n];
	rep(i, n){
		players[i] = k;
	}*/
	rep1(i, q){
		int x;
		cin >> x;
		player[x]++;
	}
	ll tmp;
	rep1(i, n){
		tmp = k - q + player[i];
		//cout << tmp << " ";
		if(tmp>0) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
