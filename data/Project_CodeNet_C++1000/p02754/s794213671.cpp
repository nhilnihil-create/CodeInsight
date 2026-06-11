#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define mp make_pair
ll power(ll a,ll b)
{ll result=1;
while(b>0)
{if(b%2==1)
 result*=a;
 a*=a;
 b/=2;
}
return result;
}
int main()
{ios_base::sync_with_stdio(false);
    cin.tie(NULL);
ll n,a,b;
cin>>n>>a>>b;
ll temp=n/(a+b);
ll temp1=n%(a+b);
if(temp1<=a)
cout<<temp*a+temp1;
else
cout<<temp*a+a;
}
