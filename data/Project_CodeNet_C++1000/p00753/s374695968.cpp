#include <iostream>
#define N 123457*2

using namespace std;

int main(void){
	int n,i,j,f,first,last;
	int prime[N]={0};
	prime[0]=2;
	for (i=3;i<=N;i++){
		for(j=0;prime[j];j++) if(i%prime[j] == 0) break;
		if(!prime[j])prime[j]=i;
	}
	while(cin>>n,n){
		for(j=0;;j++) if(n < prime[j]){first=j; break;}
	        for(j=0;;j++) if(2*n < prime[j]){last=j; break;}
	      	cout<<last-first<<endl;
	}
	return 0;
}