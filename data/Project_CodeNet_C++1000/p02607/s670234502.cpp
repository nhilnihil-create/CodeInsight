#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
const int M=1e9+7;
int main(){
	int n;
	cin>>n;
	int a[n+1];
	int ans=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int j=1;j<=n;j++){
		if(j&1 && a[j]&1)ans++;
	}
	cout<<ans;
	return 0;
}