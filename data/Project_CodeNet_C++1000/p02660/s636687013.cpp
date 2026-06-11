#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}
 
//Write From this Line

//const ll mod = 1e9+7;
//const ll mod = 998244353;
int main()
{
	ll n;
	cin >> n;
	ll ans = 0;

	for(ll i = 2; i * i < n; i++){
		ll count = 0;
		while(n % i == 0){
			n /= i;
			count++;
		}
		ll hiku = 1;
		while(1){
			count -= hiku;
			hiku ++;
			if(count >= 0) ans++;
			else break;
		}
	}
	if(n != 1) ans++;
	cout << ans << endl;
}
