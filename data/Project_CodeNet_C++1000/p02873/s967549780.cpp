#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fast ios::sync_with_stdio(false); cin.tie(NULL);
#define loop(n) for(int i=0; i<n; i++)
#define rep(i,start,n) for(int i=start; i<n; i++)

void solve(){
	string s;cin >> s;
	int n = s.length()+1;

	vector<int> a(n);

	rep(i,0,n-1)
	if(s[i] == '<') a[i+1] = max(a[i+1], a[i]+1);

	for(int i = n-1; i >=0; i--)
	if(s[i] == '>') a[i] = max(a[i], a[i+1]+1);

	int ans = 0;
	for(auto i : a)ans += i;
	cout << ans << endl;
}
	
signed main(){
    fast;    
    // int t;cin>>t;while(t--)
    solve();    
    return 0;
}
