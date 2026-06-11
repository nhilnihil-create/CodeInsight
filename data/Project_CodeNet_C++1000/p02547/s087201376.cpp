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
while(n--)
{int x,y;
 cin>>x>>y;
 if(x==y)
 count++;
 else if(count==3)
 break;
 else
 count=0;
 
}
if(count>=3)
cout<<"Yes";
else
cout<<"No";
}
