#include<iostream>
#include<algorithm>
using namespace std;
main(){
	int data[101];
	for(int i=0;i<=100;++i)data[i]=0;
	int tmp;
	while(cin>>tmp)data[tmp]++;
	int ans=0;
	for(int i=1;i<=100;++i)ans=max(ans,data[i]);
	for(int i=0;i<=100;++i)
		if(data[i]==ans)cout<<i<<endl;
}