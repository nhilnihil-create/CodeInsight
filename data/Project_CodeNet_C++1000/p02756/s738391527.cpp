#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define FOR(i, n) for(int i = 1; i<=n; i++)
#define F0R(i, n) for(int i = 0; i<n; i++)
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
bool rev = 0;
deque<char> me;
string s, ans;
int q, tt, ff;
char gg;

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> s;
	for(auto u : s)
		me.pb(u);

	cin >> q;
	while(q--){
		cin >> tt;
		if(tt == 1){
			rev ^= 1;
			continue;
		}
		cin >> ff >> gg;
		if(ff == 1) {
			if(rev) me.pb(gg);
			else me.push_front(gg);
		}
		else{
			if(rev) me.push_front(gg);
			else me.pb(gg);
		}
		/*for(auto u : me){
			cout << u;
		} cout << endl;*/
	}

	for(auto u : me)
		ans += u;

	if(rev) reverse(ans.begin(), ans.end());
	cout << ans << endl;

	cout.flush();
	return 0;
}