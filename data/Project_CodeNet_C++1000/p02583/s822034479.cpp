#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fast ios::sync_with_stdio(false); cin.tie(NULL);
#define rep(n) for(int i=0; i<n; i++)
#define rep1(i,n) for(int i=0; i<n; i++)
const int INF = 2e18;

void solve(){
	int n;cin>>n;
	int l[n];rep(n)cin>>l[i];

	sort(l,l+n);
	int ans = 0;
	for(int i=0;i<n-2;i++){
		for(int j=i+1;j<n;j++){
			for (int k = j + 1; k < n; k++) 
                if (l[i] + l[j] > l[k] 
                    && l[i]!=l[j] && l[i]!=l[k] && l[j]!=l[k]) 
                    ans++; 
		}
	}
	cout<<ans<<endl;


}
	
signed main(){
    fast;    
    // int t;cin>>t;while(t--)
    solve();    
    return 0;
}