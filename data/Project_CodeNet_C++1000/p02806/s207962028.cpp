#include<bits/stdc++.h>
using namespace std;
const int N=55;
map<string,int>mp;
int n,t[N],i,ans;
string X,s;
int main(){
	cin>>n;
	for(i=1;i<=n;++i)cin>>s>>t[i],mp[s]=i;
	cin>>X;
	for(i=mp[X]+1;i<=n;++i)ans+=t[i];
	cout<<ans<<endl;
}