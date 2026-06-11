#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n,m;
 cin>>n>>m;
 int p[m];
 string s[m];
 for(int i=0;i<m;i++)
 {
 	cin>>p[i]>>s[i];
 }
 int a[n+1]={0};
 int pen=0,cs=0;
 for(int i=0;i<m;i++)
 {
 	if(s[i]=="WA")
 	{
 		if(a[p[i]]>=0)
 		a[p[i]]++;
	 }
	 else{
	 	if(a[p[i]]>=0)
	 	{
		 cs++;
		 pen+=a[p[i]];
	 a[p[i]]=-1;
}
}
 }
 cout<<cs<<" "<<pen;
}