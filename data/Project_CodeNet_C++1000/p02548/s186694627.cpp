#include <bits/stdc++.h>

using namespace std;

#define IOS ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);

#define endl "\n";


#define mod 1000000007
#define loop(i,s,n)  for(ll i=s;i<n;i++)
#define test  ll t; cin>>t; while(t--)
#define p push_back
typedef long long ll;
int main()
{
ll n,i,j,k,count=0,sum=1;
cin>>n;
ll a[n]={0};
string s;
for(i=1;i<=n-1;i++)
{count+=(n-1)/i;}
cout<<count;




    return 0;
}


