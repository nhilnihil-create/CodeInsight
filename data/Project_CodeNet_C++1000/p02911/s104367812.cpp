#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,q;
	cin>>n>>k>>q;
	int s[q],p[n];
	for(int i=1;i<=n;i++)p[i]=k-q;
	for(int i=1;i<=q;i++){
		cin>>s[i];
		p[s[i]]++;
	}
	for(int i=1;i<=n;i++){
		if(p[i]>0)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}
