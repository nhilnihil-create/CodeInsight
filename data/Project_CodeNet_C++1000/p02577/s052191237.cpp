#include<bits/stdc++.h>
using namespace std;
const int MOD=1000000007;
#define ll long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
int main()
{
ll s=0,i,l;
char n[2000010];
cin>>n;
l=strlen(n);
for(i=0;i<l;i++)
{
	s=s+n[i]-48;
}
 
 
 
if(s%9==0)
cout<<"Yes"<<endl;
else
cout<<"No"<<endl;
}