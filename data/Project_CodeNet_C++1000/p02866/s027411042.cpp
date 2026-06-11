#include<iostream>
#include<algorithm>
using namespace std;
const int mod=998244353;
long long a[100010];
long long n,x;
long long ksm(long long a,long long b){
	long long res=1;
	while(b){
		if(b&1){
			res*=a;
			res%=mod;
		}
		a*=a;
		a%=mod;
		b>>=1;
	}
	return res;
}
 
int main(){
	cin>>n;
	int flag=0;
	cin>>x;
	long long  ans=x;
	if(x!=0) flag=1;
	for(int i=1;i<n;i++){
		cin>>x;
		a[x]++;
		if(x==0) flag=1;
		ans=max(ans,x);
	}
	if(flag){
		cout<<0<<"\n";
	}
	else{
	long long sum=1;
		for(int i=2;i<=ans;i++){
			sum*=ksm(a[i-1],a[i]);
			sum%=mod;
		}
		cout<<sum<<"\n";//printf("%lld\n",sum);
	}
	return 0;
} 