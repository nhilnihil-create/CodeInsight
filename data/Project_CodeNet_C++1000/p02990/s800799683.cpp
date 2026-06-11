#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <string>
#include <iomanip>
using namespace std;
long long mod=1e9+7;
struct all{
	vector<long long> kai,gya,nck;
	all(long long n){
		kai.resize(n+1);
		gya.resize(n+1);
		nck.resize(n+1);
	}
	long long pow(long long x,long long n){
		long long ret=1;
		if(n>0){
			ret=pow(x,n/2);
			if(n%2==0){
				(ret=(ret*ret))%=mod;
			}else{
				(ret=((ret*ret)%mod)*x)%=mod;
			}
		}
		return ret;
	}
	long long inv(long long n){
		return pow(n,mod-2);
	}
	vector<long long> cul(long long n){
		kai[n]=n;
		for(int i=n-1;i>0;i--){
			(kai[i]=kai[i+1]*i)%=mod;
		}
		gya[1]=inv(1);
		for(int i=2;i<=n;i++){
			(gya[i]=gya[i-1]*inv(i))%=mod;
		}
		for(int i=1;i<=n;i++){
			(nck[i]=kai[n+1-i]*gya[i])%=mod;
		}
		nck[0]=1;
		nck[n]=1;
		return nck;
	}
};
int main(){
	int n,k;
	cin>>n>>k;
	all nii(n-k+1);
	all mii(k-1);
	vector<long long> a=nii.cul(n-k+1);
	vector<long long> b=mii.cul(k-1);
	for(int i=1;i<=k;i++){
		if(n-k+1<i){
			cout<<0<<endl;
		}else{
			cout<<a[i]*b[i-1]%mod<<endl;
		}
	}
	return 0;
}
