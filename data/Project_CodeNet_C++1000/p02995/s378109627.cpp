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
	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	ll A, B, C;
	A = b / c - (a + (c-1)) / c + 1;
	B = b / d - (a + (d-1)) / d + 1;
	ll k = (c * d) / __gcd(c,d);
	C = b / k - (a + (k-1)) / k + 1;
	ll nene = A + B - C;
	cout << b - a + 1 - nene << endl;
}
