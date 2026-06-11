#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
#define pb push_back
#define sx 200007
int main()
{
   ll a,b,k;
   cin>>a>>b>>k;
   ll mini=min(a,k);
   k=k-mini;
   a=a-mini;
   mini=min(b,k);
   b=b-mini;
   k=k-mini;
   cout<<a<<" "<<b<<endl;
   return 0;
}
