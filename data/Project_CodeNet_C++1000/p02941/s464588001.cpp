#include<bits/stdc++.h>
using namespace std;
#define forn(i, n)             for(int i = 0; i < n; i ++)
#define forn1(i, n)            for(int i = 1; i <= n; i ++)
#define loop(i, sta, end, inc) for(int i = sta; i <= end; i += inc)
#define itr(it, l)             for(auto it = l.begin(); it != l.end(); it ++)
#define in(a, b, c)            assert( b <= a && a <= c)
#define pb push_back
#define ll long long int
#define fi first
#define se second
#define ii  pair<long long int, long long int>
#define vi  vector <long long int>
#define vii vector <pair <long long int, long long int > >
#define all(cont)  cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define what_is(x) cerr<<#x<<" ="<<x<<" ";
#define error(args...)  { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define LINT_MAX  9223372036854775807
#define LINT_MIN -9223372036854775808
#define EPS 1e-9
#define MOD 1000000007
#define DEBUG 0
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#ifndef LOCAL
#pragma GCC optimize ("Ofast")
#define endl '\n'
#define range 200010
#endif

template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }
void err(istream_iterator<string> it) { cerr<<endl;}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    if(DEBUG == 0)return;
	cerr << *it << " = " << a <<" ";
	err(++it, args...);
}
int n;
vi a,b;
int completed[range];
int main(){

	//freopen("input.txt","r",stdin);
	clock_t clk = clock();
	cin>>n;
	a.resize(n),b.resize(n);
	forn(i,n)cin>>a[i];
	forn(i,n)cin>>b[i];

	ll cnt = 0;

	while(true){
		int change = 0;
		forn(i,n){
			ll x = b[(i-1+n)%n],y = b[(i+1+n)%n];
			if(completed[i])continue;
			if(x+y>b[i])continue;
			change++;
			ll t = b[i]%(x+y);
			if(t<a[i]){
				ll p = b[i]-a[i];
				if(p%(x+y) != 0){
					cnt = -1;
				}
				else{
					cnt += p/(x+y);
					b[i] = a[i];
					completed[i] = 1;
				}
			}
			else{
				cnt += (b[i])/(x+y);
				b[i] = t;
				if(b[i] == a[i]){
					completed[i] = 1;
				}
			}
		}
		/*forn(i,n)cout<<b[i]<<" ";cout<<endl;
		forn(i,n)cout<<a[i]<<" ";cout<<endl;
		cout<<change<<endl;*/
		if(change == 0 || cnt == -1)break;
	}
	bool pos = true;
	forn(i,n){
		if(a[i] != b[i])pos = false;
	}
	if(pos)
		cout<<cnt;
	else
		cout<<-1;



    cerr << endl << setprecision(10) << fixed << (double)(clock() - clk) / CLOCKS_PER_SEC;
    return 0;
}



