#include<iostream>
#define MAX 500000
#include<algorithm>

using namespace std;
int main(){
	bool pri[600000];
	fill(pri,pri+MAX+10,1);
	pri[0]=pri[1]=0;
	for(int i=0;i*i<MAX;i++)
	if(pri[i]){
		for(int j=i*2;j<=MAX;j+=i)
		pri[j]=0;
	}
	int n,ans;
	while(cin>>n,n){
		ans=0;
		for(int i=n+1;i<=2*n;i++)
		if(pri[i])
		ans++;
		cout<<ans<<endl;
	}
	
	return 0;
}