#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	string s;
 	cin>>s;
 	int i,n=s.length();
 	for(i=0;i<n;i++)
 	if(s[i]=='?')
 	s[i]='D';
 	cout<<s<<endl;
 	/*int a[n];
 	memset(a,0,sizeof(a));
 	if(s[0]=='D')
 	a[0]=1;
 	int ans=0;
 	if(s[0]=='D')
 	ans=1;
 	for(i=1;i<n;i++)
 	{
 	  if(s[i]=='D')
	   {
	   	 	if(s[i-1]=='P')
	   	 	a[i]=a[i-1]+2;
	   	 	else
	   	 	a[i]=a[i-1]+1;
	   }
	   else if(s[i]=='P' && s[i-1]!='P')
	   a[i]=a[i-1];
	   ans=max(ans,a[i]);	
	}
	cout<<ans<<endl;*/
	return 0;
}

