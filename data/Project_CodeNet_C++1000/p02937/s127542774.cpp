#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=mod*mod*3LL;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;
#define int long long
signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    int pra[26];
    memset(pra, -1,sizeof(pra));
    vector<vector<int> > v(n, vector<int> (26));
    for(int i=n-1;i>=0;i--){
    	int num = s[i] - 'a';
    	pra[num] = i;
    }
    for(int i=n-1;i>=0;i--){
    	for(int j=0;j<26;j++){
    		if(pra[j] == -1) v[i][j] = -1;
    		else if(pra[j] <= i) v[i][j] = n - i + pra[j];
    		else v[i][j] = pra[j] - i;
    	}
        int num = s[i] - 'a';
        pra[num] = i;
    }
    int ans = 1;
    int tnow = 0;
    int snow = 0;
    if(s[0] == t[0]) tnow++;
    while(tnow < m){
    	if(v[snow][t[tnow] - 'a'] == -1) {
    		cout << -1 << endl;
    		return 0;
    	}
    	ans += v[snow][t[tnow] - 'a'];
    	snow += v[snow][t[tnow] - 'a'];
    	snow %= n;
    	tnow++;
    }
    cout << ans << endl;
    return 0;
}
