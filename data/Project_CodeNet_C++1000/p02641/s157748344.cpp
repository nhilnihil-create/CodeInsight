#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
const ll maxi =20000;
#define ip pair<ll,ll>
#define mp make_pair
int main()
{ 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);


int x,n;
cin>>x>>n;
bool a[1000];

for(int i=1;i<=1000;i++)
a[i]=false;

for(int i=0;i<n;i++){
  int a1;
  cin>>a1;
  a[a1]=true;
}
int mindif=INT_MAX;
int ans=x;
for(int i=-1000;i<=1000;i++)
{
if(abs(x-i)<mindif&&i>0&&a[i]==false){ans=i;mindif=abs(x-i);}
else if(i<=0&&abs(x-i)<mindif){ans=i;mindif=abs(x-i);}
}
cout<<ans<<endl;


}