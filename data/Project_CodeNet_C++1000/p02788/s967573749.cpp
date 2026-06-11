//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

int main() {
    long long int ans = 0;
    ll tmp;
    ll n, d, a;
	cin >> n >> d >> a;
	priority_queue<pair <ll, ll > > mons; // x, h
	priority_queue<pair <ll, ll > > bomb; // ひだりはし、与ダメージ
	ll x, h;
	REP(i, n){
		cin >> x >> h;
		mons.push(make_pair(x,h));
	}
	ll nowa = 0;
	pair< ll, ll> nm;
	ll thro;
	REP(i, n){
		nm = mons.top();
		mons.pop();
		while(!bomb.empty() && nm.first < bomb.top().first ){
			nowa -= bomb.top().second;
			bomb.pop();
		}
		if(nm.second > nowa){
			thro = (nm.second - nowa + a - 1) / a;
			bomb.push(make_pair(nm.first - 2 * d, a * thro));
			nowa += a * thro;
			ans += thro;
			//cout << nm.first << " " << thro << endl;
		}  
	}
    cout << ans << endl;
}