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
ll n,count=0;
cin>>n;
for(ll i=1;i<n;i++)
{ll temp=n/i;
 if(n%i==0)
 temp--;
 count+=temp;
}
cout<<count;
}
