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
const int mxn=1e5+5;
int n,k,v[3];
string t;
bool used[mxn];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	cin >> n >> k;
	ll ans = 0LL;
	for(int i=0; i<3; i++)cin >> v[i];
	cin >> t;
	for(int i=0; i<n; i++){
		if(t[i]=='r')t[i]='2';
		else if(t[i]=='p')t[i]='1';
		else t[i]='0';
		if(i<k){
			ans += v[t[i]-'0'];
			used[i]=1;
		}else{
			if(t[i]==t[i-k]&&used[i-k])continue;
			ans += v[t[i]-'0'];
			used[i]=1;
		}
	}
	cout << ans << endl;
}
	
// READ & UNDERSTAND
// ll, int overflow, array bounds, memset(0)
// special cases (n=1?), n+1 (1-index)
// do smth instead of nothing & stay organized
// WRITE STUFF DOWN
	