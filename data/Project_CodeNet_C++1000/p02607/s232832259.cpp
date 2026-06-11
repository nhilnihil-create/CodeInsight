#include<bits/stdc++.h>
 
using namespace std;

#define int long long

signed main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
//	int t;
//	cin >> t;
//	while(t--){
		int n;
		cin >> n;
		int a[n],ans=0;
		for(int i=0;i<n;i++){
			cin >> a[i];
			if(i%2==0&&a[i]%2==1){
				ans++;
			}
		}
		cout << ans << endl;
//	}
}
