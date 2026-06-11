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
string s;
cin>>s;
ll n=s.length();
if(s[n-1]!='s')
cout<<s<<"s";
else
cout<<s<<"es";
}
