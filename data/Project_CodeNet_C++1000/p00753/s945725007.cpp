#include <bits/stdc++.h>
using namespace std;
bool num[300000];
int main() {
	for(int i=2;i<548;i++)if(!num[i])for(int j=i*2;j<300000;j+=i)num[j]=1;
	int n;
	while(cin>>n,n){
		int ans=0;
		for(int i=n+1;i<=2*n;i++)if(!num[i])ans++;
		cout<<ans<<endl;
	}
}