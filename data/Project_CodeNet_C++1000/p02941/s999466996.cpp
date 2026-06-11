#include<bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define f first
#define s second 
#define sz(s) (int)s.size()
#define all(s) s.begin(), s.end()
#define int long long
#define forn(i, x, y) for(int i = x; i <= y; i++)
#define forev(i, y, x) for(int i = y; i >= x; i--)

using namespace std;

const int maxn = (int)3e5 + 100;
const int mod = (int)1e9 + 7;
const int P = (int)1e6 + 7;
const int inf = (int)1e9 + 7;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef long double ld;

using namespace std;

int n, a[maxn], b[maxn], cnt, ans;
set<pii> s;
int prv(int x){
	if(x == 1) return n;
	return x - 1;
}
int nxt(int x){
	if(x == n) return 1;
	return x + 1;
}
main () {
	int cnt=0;
	cin >> n;
	forn(i, 1, n)
		cin >> a[i];
	forn(i, 1, n)
		cin >> b[i], s.insert(mp(b[i], i));
	while(sz(s)){
		cnt++;
		if(cnt==5000000){
			cout<<-1;
			return 0;
		}
		int val = s.rbegin()->f, pos = s.rbegin()->s;
		int l=0,r=1000000000,res=-1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(val-mid*b[prv(pos)]-mid*b[nxt(pos)]>=a[pos]){
				res=mid;
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		ans+=res;
		val = val-res*b[prv(pos)]-res*b[nxt(pos)];
		s.erase(*s.rbegin());
		if(val!=a[pos]){
			s.insert(mp(val,pos));
		}
		b[pos] = val;
	}
	cout << ans;
}