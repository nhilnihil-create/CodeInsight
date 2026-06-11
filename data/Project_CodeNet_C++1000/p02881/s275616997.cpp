  #include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
  ll n,j,s,l;
  cin>>n;
  ll ans = n-1;
  for(ll i=1;i<=sqrt(n);i++)
  {
    if(n%i==0){
      j = i;
      s = n/j;
  
   ans = min(ans,(j-1)+(s-1));
    l = 1;
  }
 } 
  if(l==1)
     cout<<ans<<endl;
     else
     cout<<n-1<<endl;
  
}