#include <iostream>
using namespace std;
int main(){
	int i,j,n,p[246920]={0};
	for(i=2;i<123457;i++) if(!p[i]) for(j=i;(j+=i)<246914;p[j]=1);
	for(i=2;i<246914;i++) p[i]=p[i-1]+!p[i];
	while(cin>>n,n) cout<<p[n+n]-p[n]<<endl;
}