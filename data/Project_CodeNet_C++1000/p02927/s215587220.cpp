#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ldb long double
#define rep(i, x, n, j) for(int i=x;i<(int)n;i+=j)
#define F first
#define S second
#define per(i, x, n, j) for(int i=(int)n-1;i>=0;i-=j)
#define all(v) v.begin(),v.end()
#define sz(a) (int)a.size()

const int N = 2000100;
const ll MOD = 1e9+7;
const ll inf = 1e18+5;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;

int _;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m, d; cin >> m >> d;
	int counter=0;
	rep(i,20,d+1,1){
		string s = to_string(i);
		if((s[1]-'0')<2) continue;
		if((s[0]-'0')*(s[1]-'0')>=1 && (s[0]-'0')*(s[1]-'0')<=m)
		++counter;
	}
	cout << counter << endl;
	return 0;
}
