#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//Write From this Line

int main()
{
	ll t1, t2;
	cin >> t1 >> t2;
	ll a1, a2, b1, b2;
	cin >> a1 >> a2 >> b1 >> b2;
	//if(t1 * a1 + t2 * a2 == t1*b1 + t2*b2){
	a1 *= t1, a2 *= t2;
	b1 *= t1, b2 *= t2;
	
	a2 += a1;
	b2 += b1;

	if(a2 == b2){
		cout << "infinity" << endl;
		return 0;
	}
	if(a2 < b2){
		swap(a1,b1);
		swap(a2,b2);
	}

	ll d = a2 - b2;
	ll c = b1 - a1;
	ll ans = 0;
	if(c > 0){
		ans = (c-1)/d+1;
		ans *= 2;
		ans--;
		if(c%d==0)ans++;
	}
	cout << ans << endl;
}
