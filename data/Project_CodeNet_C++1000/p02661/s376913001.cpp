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


int main(){
	int n;cin>>n;
	vector<ll> a(n);
	vector<ll> b(n);
	for(int i = 0; i < n; i++) {
		ll A,B;cin>>A>>B;
		a[i] = A;
		b[i] = B;
	}
	sort(ALL(a));
	sort(ALL(b));
	reverse(ALL(b));
	if (n % 2 == 1){
		ll x = a[n / 2];
		ll y = b[n / 2];
		cout << y - x + 1 << endl;
		return 0;
	}
	else{
		ll x = (a[n/2 - 1] + a[n / 2]);
		ll y = (b[n/2 - 1] + b[n / 2]);
		cout << y - x + 1 << endl;
		return 0;
	}
	return 0;
}