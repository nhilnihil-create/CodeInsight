#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define PI acos(-1)
#define EPS 1e-5
#define sz(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define forn(i, n) for(ll i=0;i<(ll)n;i++)
#define fi first
#define se second
 

int main() {
	int n;
	cin >> n;
	if(n < 10) {
		if(n == 2||n==4||n==5||n==7||n==9)
			cout << "hon" << endl;
		else if(n ==0||n==1||n==6||n==8)
			cout << "pon" << endl;
		else cout << "bon" << endl;
		return 0;
	}
	n = n%10;
 	if(n == 2||n==4||n==5||n==7||n==9)
			cout << "hon" << endl;
	else if(n ==0||n==1||n==6||n==8)
			cout << "pon" << endl;
	else cout << "bon" << endl;
	
	return 0;
}

