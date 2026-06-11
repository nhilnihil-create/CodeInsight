#include<bits/stdc++.h>
using namespace std;
string s[55];int t[55];
map<string,int> m;
int main(){
	int n;string x;
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>s[i]>>t[i],m[s[i]]=i;
	cin>>x;
	int st=m[x]+1,sum=0;
	for(int i=st;i<=n;++i)
		sum+=t[i];
	cout<<sum;
	return 0;
} 