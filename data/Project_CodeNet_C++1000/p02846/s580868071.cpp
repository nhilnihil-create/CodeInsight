#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef set<int> si;
typedef set<ll> sl;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b)-1; i>=(a); --i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define F first
#define S second

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);
	ll T1, T2, A1, A2, B1, B2;
	cin >> T1 >> T2;
	cin >> A1 >> A2;
	cin >> B1 >> B2;

	ll a1 = (A1 - B1)*T1;
	ll a2 = (A2 - B2)*T2;
	if(a1 > 0) {
		a1 = -a1;
		a2 = -a2;
	}
	ll w = a1 + a2;
	if(w < 0) {
		cout << 0 << endl;
		return 0;
	} else if(w == 0) {
		cout << "infinity" << endl;
		return 0;
	}

	ll ret = (a2/w)*2 - 1;
	if((a2%w) == 0) 
		ret--;
	cout << ret << endl;
	return 0;
}