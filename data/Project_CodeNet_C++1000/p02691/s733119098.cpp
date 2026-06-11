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
int main(){
	int n;
	cin >> n;
	vi a(n);
	for(int i=0; i <n; i++) cin >> a[i];
	map<int,int> m;
	lli ans = 0ll;
	for(int i=0; i < n; i++){
		int dif = i - a[i];
		if(m.find(dif) != m.end()){
			ans+=m[dif];
		}
		m[i+a[i]]++;
	}
	cout << ans << endl;
	return 0;
}
