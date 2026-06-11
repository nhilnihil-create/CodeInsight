#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mod(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	vector<ll> A(N);
	forn(i,0,N)cin >> A[i];
	ll dinero = 1000;
	ll cnt = 0;
	ll res = dinero;
	forn(i,0,N-1){
		if(A[i] < A[i+1]){
			ll puedo = dinero/A[i];
			
			cnt += puedo;
			dinero -= puedo*A[i];
			
			dinero += cnt*A[i+1];
			cnt = 0;
			res = max(res,dinero);
		}
		//else if(A[i] > A[i+1]){
			//ll puedo = dinero/A[i+1];
			//cnt += puedo;
			//dinero -= puedo*A[i+1];
		//}
		//cout << dinero << ' ' << cnt << '\n';
	}
	cout << res << '\n';
	return 0;
}
/*
__builtin_mul_overflow(x,y,&x)
-fsplit-stack
*/
