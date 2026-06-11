#include <iostream>

using namespace std;

int main(){
	
	cin.tie(0); ios_base::sync_with_stdio(0);
	long long n,x;
	cin>>n;
	int res = 0;
	for(long long i = 2;i*i<=n;i++)if(n%i==0){
		x = n;
		while(x%i==0)x/=i;
		if(x%i==1)res++;
		if(n/i!=i){
			long long d = n/i;
			x = n;
			while(x%d==0)x/=d;
			if(x%d==1)res++;
		}
	}
	else if((n-1)%i==0){
		res++;
		if((n-1)/i!=i)res++;
	}
	res+=1;
	if(n>2)res++;
	cout<<res<<endl;
	
	return 0;
}