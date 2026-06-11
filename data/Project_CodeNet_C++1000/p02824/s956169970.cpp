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
	ll n, m, v, p;
	cin >> n >> m >> v >> p;

	vector<ll> a(n);
	rep(i, n)cin>>a[i];
	SORT(a); rSORT(a);

	ll ok = 0, ng = n;	
	while(ng - ok > 1){
		ll mid = ok + ng; mid /= 2;
		if(mid < p){
			ok = mid;
			continue;
		}

		//上のp-1個には投票していい。
		ll use = (p-1) * (m);

		//a[mid]以下にも投票していい。
		use += (n - mid) * m;

		// a[p-1] ~ a[mid-1]に入れても良い分だけ入れる
		for(int i = p - 1; i <= mid - 1; i++){
			// 0票以上入れること。マイナスは無理
			use += min(m,max(0ll, (a[mid] + m) - a[i]));
		}
		bool muri = false;
		if(a[mid] + m < a[p-1]){
			// 無理
			muri = true;
		}
		if(use >= m * v);//ok
		else muri = true;
		if(muri){
			ng = mid;
		} else {
			ok = mid;
		}
	}
	cout << ok + 1 << endl;
}
