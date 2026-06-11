#include<bits/stdc++.h>
using namespace std;
#define ll int
#define sort(v) sort(v.begin(),v.end())
#define pb push_back

/*ll ar[1000000+9]={0};
void seiv()
{
ll n=1000000,i,j;
ar[1]=1;
for(i=4;i<=n;i+=2)ar[i]=1;
for(i=3;i<=n;i+=2)
{
if(ar[i]==0)
{
for(j=i*i;j<=n;j+=i*2)ar[j]=1;
}
}
}
*/
int main()
{
  ll a,b,c,i,j,k=0;map<string,ll>m,n;
 string s;
    cin>>a>>s;
    for(i=0;i+1<s.size();i++)
   {
if(s[i]!=s[i+1])k++;
   }cout<<k+1<<endl;
 }