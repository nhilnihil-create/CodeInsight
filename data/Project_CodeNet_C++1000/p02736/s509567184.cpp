#include<bits/stdc++.h>
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define ll long long
#define int ll
#define forn(i, a, b) for(int i = (a); i <= (b); ++i)
#define forev(i, b, a) for(int i = (b); i >= (a); --i)
#define VAR(v, i) __typeof( i) v=(i)
#define forit(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define file(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
 
using namespace std;
 
const int maxn = (int)1e6 + 100;
const int mod = (int)1e9 + 7;
 
#define inf mod
 
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;   
typedef vector<ll> Vll;               
typedef vector<pair<int, int> > vpii;
typedef vector<pair<ll, ll> > vpll;

int n, a[maxn];
bool found;
char s[maxn];
int C(int n, int k){
	return ((n & k) == k);
}
bool get(){
	bool ans = 0;
	forn(i, 1, n)	
		if(C(n - 1, i - 1))
			ans ^= (a[i] & 1);
	return ans;
}
main () {
	scanf("%d\n%s", &n, s + 1);
	forn(i, 1, n){
		a[i] = s[i] - '0' - 1;
		found |= (a[i] == 1);
	}
	if(!found){
		forn(i, 1, n)
			a[i] >>= 1;
		printf("%d\n", 2 * get());
	}else{
		printf("%d\n", get());
	}
}