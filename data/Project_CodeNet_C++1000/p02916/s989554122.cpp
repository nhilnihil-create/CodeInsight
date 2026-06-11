#include <bits/stdc++.h>

using namespace std; 
 
#define int long long
#define M 1000000007 
 
signed main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	
//	int t;
//	cin >> t;
//	while(t--){
		int n;
		cin >> n;
		int a[n+1];
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		int b[n+1];
		for(int i=1;i<=n;i++){
			cin >> b[i];
		}
		int c[n];
		for(int i=1;i<n;i++){
			cin >> c[i];
		}
		int ans=0,lst=-1;
		for(int i=1;i<=n;i++){
			ans+=b[a[i]];
			if(lst==a[i]-1){
				ans+=c[a[i]-1];
			}
			lst=a[i];
		}
		cout << ans << endl;
//	}
}
 