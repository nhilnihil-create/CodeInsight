#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define eb emplace_back
#define mt make_tuple
#define all(x) (x).begin(), (x).end() 
#define MOD 1000000007

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;

const ll INF=LLONG_MAX;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int n,m;
	cin >> n >> m;
	string s="";
	for(int i=0; i<n; i++)s+='.';
	bool ok=1;
	int p; char x;
	for(int i=0; i<m; i++){
		cin >> p >> x;
		p--;
		if(!ok)continue;
		if(s[p]=='.')s[p]=x;
		else if(s[p]!=x){
			ok=0;
		}
	}
	if(s[0]=='0'&&n>1)ok=0;
	if(ok){
		if(s[0]=='.')s[0]=(n==1?'0':'1');
		for(int i=1; i<n; i++){
			if(s[i]=='.')s[i]='0';
		}
		cout << s << '\n';
	}else cout << -1 << '\n';
}
	
// READ & UNDERSTAND
// ll, int overflow, array bounds, memset(0)
// special cases (n=1?), n+1 (1-index)
// do smth instead of nothing & stay organized
// WRITE STUFF DOWN
