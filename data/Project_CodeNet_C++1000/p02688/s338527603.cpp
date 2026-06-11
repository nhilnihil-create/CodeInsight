#include<bits/stdc++.h>
using namespace std;
int n,k,a[110],x,y,ans;
int main(){
	cin>>n>>k;
	for (int i=0;i<k;i++){
		cin>>x;
		for (int j=0;j<x;j++){
			cin>>y;
			a[y]=1;
		}
	}
	for (int i=1;i<=n;i++) if (a[i]==0) ans++;
	cout<<ans<<endl;
	return 0;
}