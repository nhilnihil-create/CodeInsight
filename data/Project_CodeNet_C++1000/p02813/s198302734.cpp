#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100],b[100],ra[100];
int kt(int a[],int n){
	int ret=0;
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=i+1;j<=n;j++){
			if(a[j]<a[i]) cnt++;
		}
		ret+=cnt*ra[n-i];
	}
	return ret;
} 
void init(int n){
	ra[0]=1;
	for(int i=1;i<=n;i++) ra[i]=i*ra[i-1];
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	init(30);
	int num1=kt(a,n);
	int num2=kt(b,n);
	cout<<abs(num1-num2)<<'\n';
	return 0;
 } 