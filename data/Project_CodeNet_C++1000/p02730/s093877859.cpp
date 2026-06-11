#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	char s[101];
	scanf("%s",s);
	int len=strlen(s),i,flag=0,len1,len2;
	len1=len/2;
	for(i=0;i<len1;i++) // 1st step
	{
		if(s[i]!=s[len-i-1]){
			flag=1;
			cout<<"No";
			return 0;
		}
	}
	for(i=0;i<len1/2;i++)
	{
		if(s[i]!=s[len1-i-1]){
			flag=2;
			cout<<"No";
			return 0;
		}
	}
	len2=len1+1;
	for(i=len2;i<len;i++)
	{
		if(s[i]!=s[len1-(i-len2)-1]){
			flag=3;
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
	
}