#include<bits/stdc++.h>
#define int long long int
using namespace std;
#define pb push_back
int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;cin >> n;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				if(a[i]!=a[j]&&a[i]!=a[k]&&a[j]!=a[k]&&(a[i]+a[j]>a[k])&&(a[i]+a[k]>a[j])&&(a[j]+a[k]>a[i])){
					ans++;
				}
			}
		}
	}
	cout << ans << endl;


	return 0;
}
