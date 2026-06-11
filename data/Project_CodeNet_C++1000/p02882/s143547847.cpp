#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
#define FOR(i, n) for(int i = 1; i<=n; i++)
#define F0R(i, n) for(int i = 0; i<n; i++)
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
const LD pi = (LD)4 * atan(1);
LD a, b, x, ans, ar;

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> a >> b >> x;
	ar = a*a*b;
	if((LD)2*x < ar){
		ans = a*b*b;
		ans /= (LD)2*x;
		ans = atan(ans);
		ans *= (LD)180;
		ans /= pi;
		cout << fixed << setprecision(8);
		cout << ans << endl;
		return 0;
	}
	ans = (LD)2*b;
	ans -= (LD)2*x/(a*a);
	ans /= a;
	ans = atan(ans);
	ans *= (LD)180;
	ans /= pi;
	cout << fixed << setprecision(8);
	cout << ans << endl;

	cout.flush();
	return 0;
}