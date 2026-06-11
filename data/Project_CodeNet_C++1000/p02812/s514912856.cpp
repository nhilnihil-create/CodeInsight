#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<map>
#include<set> 
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<math.h>
using namespace std;
const int maxn = 1e3 + 5;
const int p = 233;
typedef unsigned long long ull;
ull hash1[maxn],hash2[maxn],P[maxn]; 
char a[maxn],b[maxn];
const int mod=1e9+7;
ull quhash(int l,int r)
{
	return hash1[r]-hash1[l-1]*P[r-l+1];
}
int main()
{
	int n;
	P[0]=1;
	for(int i=1;i<=maxn;i++)
		P[i]=P[i-1]*p;
	cin>>n;
	scanf("%s",a+1);
	b[1]='A',b[2]='B',b[3]='C';
	int len1=strlen(a+1);
	int len2=strlen(b+1);
	hash1[0]=0,hash2[0]=0;
	for(int i=1;i<=len1;i++)	
		hash1[i]=hash1[i-1]*p+a[i];
	for(int i=1;i<=len2;i++)	
		hash2[i]=hash2[i-1]*p+b[i];	
	int l=1,ans=0;
	for(;l<=len1-len2+1;)
	{
		int r=l+len2-1;
		if(quhash(l,r)==hash2[len2])
		{
			ans++;
			l=r+1;	
		}	
		else
			l++;  
	}
	cout<<ans<<endl;	
}