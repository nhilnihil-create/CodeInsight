#include<bits/stdc++.h>
#define ll long long int

using namespace std;
int main()
{
  ll n;
  cin>>n;
  if(n%1000 == 0)
    cout<<"0\n";
  else
    cout<<1000*(n/1000 + 1) - n<<'\n';
  return 0;
}
