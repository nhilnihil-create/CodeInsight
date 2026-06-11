#include<bits/stdc++.h>
using namespace std;
int l[200003],r[200003],n,k,c;
string s;
int main(){
	cin>>n>>c>>k>>s;k++;
	l[0]=(s[0]=='o');
	for(int i=1;i<s.size();i++)
		if(s[i]=='o')
			l[i]=i>=k?l[i-k]+1:1;
		else
			l[i]=l[i-1];
	r[n-1]=(s[n-1]=='o');
	for(int i=n-2;i>=0;i--)
		if(s[i]=='o')
			r[i]=r[i+k]+1;
		else
			r[i]=r[i+1];
	for(int i=0;i<n;i++)
		if(s[i]=='o'){
			int res=0;
			if(i>0)res+=l[i-1];
			if(i<n-1)res+=r[i+1];
			if(res<c)cout<<i+1<<endl; 
		}
} 