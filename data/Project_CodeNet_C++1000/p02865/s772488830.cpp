//IN THE NAME OF GOD;
//Test By Dev-C++5.11
#include<bits/stdc++.h>
#define ll  long long
#define isc ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ld long double
#define ss string
#define ww while
#define vl vector<ll>
#define pb push_back
#define in insert
#define itr iterator
#define gt goto
#define rep(i,n,j) for(ll i=n;i<j;i++)
#define tep(i,n,j) for(ll i=n;i>=j;i--)
#define co(n) cout << n ;
#define pll pair<ll,ll>
using namespace std;

ll bmm(ll a, ll b) {
	if (b == 0) return a;
	else return bmm(b, a%b);
}
ll kmm(ll a, ll b) {
	return(a*b) / bmm(a, b);
}

const ll mod = 1e9 + 7;
const ll MAXN = 2e5+5;

ll n;

int main() {
	isc;
	cin >> n;
	if(n%2==0){
		n/=2;
		cout << n-1;
	}
	else{
		n--;n/=2;
		cout << n;
	}
	return 0;
}
