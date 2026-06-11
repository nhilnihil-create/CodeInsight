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
typedef vector<int> vi;
typedef vector<vi> vvi;

int main(){__
	string s;
	cin >> s;
	int n = s.size();
	reverse(all(s));
	vector<int> sum(n);
	int tot =0;
	int pot = 1;
	map<int,int> m;
	lli ans = 0ll;
	m[0] = 1;
	for(int i=0; i <n; i++){
		int x = (s[i]-'0');
		tot = (tot + (pot * x)) % 2019;
		sum[i] = tot;
		int cont = m[tot];
		ans+=cont;
		m[tot]++;
		pot = (pot * 10) % 2019;
	}
	cout << ans << endl;
	return 0;
}
