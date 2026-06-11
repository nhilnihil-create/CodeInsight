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
typedef vector<lli> vi;
typedef vector<vi> vvi;

int main(){__
	int n;
	cin >> n;
	vi a(n),b(n);
	for(int i=0; i <n; i++){
		cin >> a[i] >> b[i];
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	lli l = 0, r = 0;
	lli ans =0;
	if(n&1){
		r = b[n/2];
		l = a[n/2];
		ans = r-l+1;
	}
	else{
		l = a[n/2] + a[(n/2)-1];
		r = b[n/2] + b[(n/2)-1];
		if(l == r){
			cout << 1 << endl;
			return 0;
		}
		if(l&1){
			ans++;
			l/=2;
			l++;
		}
		else l/=2;
		
		if(r&1){
			ans++;
			r/=2;
		}
		else r/=2;
		if(r >= l){
			lli tam= r-l+1;
			ans+= tam + tam-1;
		}
	}
	cout << ans<< endl;
	return 0;
}
				
