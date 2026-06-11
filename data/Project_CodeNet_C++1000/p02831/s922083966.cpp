#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{
      ll n,m;
      cin>>n>>m;

      ll gcd=__gcd(n,m);
      ll lcm=(n*m)/gcd;

      cout<<lcm<<"\n";
return 0;
}
