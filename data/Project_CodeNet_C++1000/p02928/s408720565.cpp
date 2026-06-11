#include<iostream>
#include<string.h>
using namespace std;
long long n,k;
long long a[1000110],c[1000010],d[1000010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
		long long sum=0;
	sum=(k+1)*k/2;
	sum-=k;
	sum%=1000000007;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[i]>a[j]){
				c[i]++;
			}
		}
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]){
				d[i]++;
			}
		}
	}

	long long ans=0;
//	cout<<sum<<endl;
	for(int i=0;i<n;i++){
//		cout<<c[i]<<"   "<<d[i]<<endl;
		ans+=(c[i]*sum);
		ans%=1000000007;
		ans+=(d[i]*(sum+k));
		ans%=1000000007;
	}
	cout<<ans<<endl;
	return 0;
}