#include<bits/stdc++.h>
#define ll long long int
#define vl vector<ll>
#define pl pair<ll,ll>
#define pb push_back
#define F first
#define S second
using namespace std;

int main()
{
	ll n,i,j,k;
	cin >> n;
	vl v(n+1,0);
    for(i=0;i<n;i++)
      cin >> v[i];
  ll mn=10000000000;
    for(i=1;i<=100;i++)
    {ll s=0;
     for(j=0;j<n;j++)
     {
       s+=(v[j]-i)*(v[j]-i);
     }
	mn=min(mn,s);
    }
  cout << mn;
	return 0;
}