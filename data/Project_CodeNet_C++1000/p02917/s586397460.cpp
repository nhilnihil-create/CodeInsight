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
		for(int i=0;i<n-1;i++){
			cin >> a[i];
		}
		int lst=a[0];
		int sum=a[0];
		for(int i=1;i<n-1;i++){
			if(a[i]<lst){
				sum+=a[i];
				lst=a[i];
			}
			else{
				sum+=lst;
				lst=a[i];
			}
		}
		sum+=lst;
		cout << sum << endl;
//	}
}
 