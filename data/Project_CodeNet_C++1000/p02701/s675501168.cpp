#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD (ll) (1e9+7)
int main()
{
	ll n;
    cin>>n;
    string x;
    map<string,int> ma;
    for(int i=0;i<n;i++)
    {
      cin>>x;
      ma[x]++;
    }
  cout<<ma.size()<<"\n";
}