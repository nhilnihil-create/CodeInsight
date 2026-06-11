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


int n;
cin>>n;
int a[n];
vector<int> freq((int)1e6+5,0);
for(int i=0;i<n;i++)
cin>>a[i];
for(ll i=0;i<n;i++)
{
  cin>>a[i];
  freq[a[i]]++;
}
ll ans=0;




for(int i=0;i<n;i++)
{ bool found=true;
  for(int j=2;j<=sqrt(a[i]);j++)
  {
    if(a[i]%j==0)
    { 
      ll x=a[i]/j;
      if(freq[x]||freq[j])found=false;
    }
  }if(found&&freq[a[i]]==1)ans++;
}
if(freq[1]==1)ans=1;
else if(freq[1]>1)ans=0;
cout<<ans<<endl;




}
