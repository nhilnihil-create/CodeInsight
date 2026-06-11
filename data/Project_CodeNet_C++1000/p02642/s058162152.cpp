#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//重複した要素の取り扱い方がよくわからない
//iでは入れずにjのときだけ入れれば良い？
int main(){
	ll n;cin>>n;
	vector<ll> a(n);
	for(ll i = 0; i < n; i++) {
		cin>>a[i];
	}
	// cout << a.size() << endl;
	sort(ALL(a));
	vector<ll> b(1000005,1);//a[i] = 1ならAの中に自身以外の約数は存在しない
	for(ll i = 0; i < n; i++) {
		ll x = a[i];
		ll mul = 2;
		if(x * mul <= a[n - 1]){
			while(x * mul <= a[n - 1]){
				b[x * mul] = 0;
				mul ++;
			}
		}
	}
	ll ans = 0;
	for(ll i = 0; i < n; i++) {
		if((i > 0 && a[i] == a[i -  1]) || (i < n - 1 && a[i] == a[i + 1])){
			continue;
		}
		else if (b[a[i]])ans++;
	}
	cout << ans << endl;
	for(int i = 0; i < b.size(); i++) {
		// cout << i << " " << b[i] << endl;
	}

	return 0;
}