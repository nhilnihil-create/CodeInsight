#include<iostream>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
using namespace std;

bool prime[7000000];

int main(){
	rep(i,7000000)prime[i]=true;
	prime[0]=prime[1]=false;
	loop(i,2,10000){
		for(int j=i*2;j<7000000;j+=i){
			prime[j]=false;
		}
	}
	long long a,d,n;
	while(cin>>a>>d>>n,a||d||n){
		long long num=a,cnt=0;
		while(cnt!=n){
			if(prime[num])cnt++;
			if(cnt!=n)num+=d;
		}
		cout<<num<<endl;
	}
	return 0;
}