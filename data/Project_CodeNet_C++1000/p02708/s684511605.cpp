#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(0);cin.tie(0);
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define forn(i,a,n) for(int i=a; i < n; i++)
typedef long long int lli;
typedef long double Double;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int mod =  1e9+7;
int main(){__
	int n,k;
	cin >> n >> k;
	lli ans = 0ll;
	int l = 0,r = n;
	lli suml = 0ll, sumr = 0ll;
	while(l <= n){
		suml+=l;
		sumr+=r;
		lli dif = sumr - suml +1ll;
		if(l >= k-1)
			ans = (ans + dif) % mod;
		l++;
		r--;
	}
	cout<< ans << endl;
	return 0;
}
