// READ & UNDERSTAND
// ll, int overflow, array bounds
// special cases (n=1?), n+1 (1-index)
// do smth instead of nothing & stay organized
// WRITE STUFF DOWN

#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end() 
#define MOD 1000000007

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;

ll INF=LLONG_MAX;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int n,m; string s;
	cin >> n >> m >> s;
	vi f(n+1,1e9);
	f[n]=0; queue<int>q;
	q.push(0);
	for(int i=n-1; i>=0; i--){
		while(1){
			if(q.empty()){
				cout << -1 << endl; 
				return 0;
			}
			if((int)q.size()>m||q.front()==(int)1e9)q.pop();
			else break;
		}
		if(s[i]=='0')f[i]=q.front()+1;
		q.push(f[i]);
	}
	vi ans;
	int x = 0;
	int cur = f[0];
	while(x<n){
		cur--;
		int i=1;
		while(f[x+i]!=cur)i++;
		ans.pb(i);
		x += i;
	}
	for(auto i:ans)cout << i << ' ';
	cout << endl;
}	
