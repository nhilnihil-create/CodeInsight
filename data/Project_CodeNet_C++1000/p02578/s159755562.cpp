#include<bits/stdc++.h>
using namespace std;

int a[200005];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)cin >> a[i];
	long long ans=0;
	for(int i=2;i<=n;i++){
		if(a[i]<a[i-1]){
			ans+=(a[i-1]-a[i]);
			a[i]=a[i-1];
		}
	}
	cout << ans << '\n';
	return 0;
}

