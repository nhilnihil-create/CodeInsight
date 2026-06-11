#include<iostream>
using namespace std;
typedef long long int ll;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string a;
  ll n,x;
  cin>>n;
  cin>>a;
  for(ll i=0;i<a.size();i++)
  {
    x=(int)a[i];
    ll k=0;
    while(k!=n)
    {
        k++;
		x++;
        if(x==91)
          x=65;
    } 
    a[i]=(char)x;
  }
  cout<<a<<"\n";
  return 0;
}  