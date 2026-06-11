#include<bits/stdc++.h>                       
const int N=400005;
using namespace std;
int k,n,c,ans,l[N],r[N];
string s;
int main(){
    cin>>n>>k>>c>>s;
    int i=1,kk=0;
    while(kk<k)
    {
    	if(s[i-1]=='o') kk++,l[kk]=i,i+=c;
		i++;
	}
	i=n,kk=k;
	while(kk>0)
    {
    	if(s[i-1]=='o') r[kk]=i,kk--,i-=c;
    	i--;
	}
	for(int j=1;j<=k;j++)
		if(r[j]==l[j]&&r[j]!=0) cout<<l[j]<<endl;
	return 0;
}
//68871358
//76140264
//25446011
//200841159
//914174775