#include <bits/stdc++.h>
using namespace std;
const int N=220000;
string s;
int l[N],r[N];
int n,k,c;
int main(){
	cin>>n>>k>>c>>s;int i=1,kk=1;
	while(kk<=k){
		if(s[i-1]=='o')l[kk++]=i,i+=c;
		++i; 	}	
	i=n,kk=k;
	while(kk){
		if(s[i-1]=='o')r[kk--]=i,i-=c;
		--i; 
	}
	
	for(i=1;i<=k;++i)if(l[i]==r[i])printf("%d\n",l[i]);
	
	return 0;
}
