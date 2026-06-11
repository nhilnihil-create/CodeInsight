#include <iostream>
using namespace std;
int prime[1000001];
int a,d,n,cnt,ans;



int main(){
	prime[1]=0;
	for(int i=2;i<1000001;i++){
		prime[i]=1;
	}
	for(int i=2;i<=1000;i++){
		if(prime[i]==0)continue;
		int k=i*i;
		while(k<1000001){
			prime[k]=0;
			k+=i;
		}
	}
	//cout <<"OK"<<endl;
	while(1){
		cin >>a >>d >>n;
		if(!(a||d||n))break;
		cnt=0;
		for(int i=a;i<=1000001;i+=d){
			cnt+=prime[i];
			if(cnt==n){
				ans=i;
				break;
			}
		}
		cout <<ans<<endl;
	}
}