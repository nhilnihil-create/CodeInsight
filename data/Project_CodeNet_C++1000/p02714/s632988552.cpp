#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
ll gcd(int a,int b)
{
if(a>b)
swap(a,b);
 
if(a==0)
  return b;
return gcd(b%a,a);
 
}
int main()
{ 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);

ll n;
cin>>n;
string s;
cin>>s;
ll ans=0;
ll zer=0;
for(ll i=0;i<n;i++)
{ ll blue=0;
  ll red=0;
  ll green=0;

  for(ll j=i+1;j<n;j++)
  {
    if(s[i]=='R')
    {if(s[j]=='B')
     {if((i+j)%2==0&&s[(i+j)/2]=='G')
       ans+=max(zer,green-1);
     else ans+=green;
      }
     if(s[j]=='G')
     {
     if((i+j)%2==0&&s[(i+j)/2]=='B')
     ans+=max(zer,blue-1);
     else ans+=blue;
     
     }
    }



    if(s[i]=='G')
    {if(s[j]=='B')
     {if((i+j)%2==0&&s[(i+j)/2]=='R')
     ans+=max(zer,red-1);
     else ans+=red;
      }
     if(s[j]=='R')
     {
     if((i+j)%2==0&&s[(i+j)/2]=='B')
     ans+=max(zer,blue-1);
     else ans+=blue;
     
     }
    }



    if(s[i]=='B')
    {if(s[j]=='R')
     {if((i+j)%2==0&&s[(i+j)/2]=='G')
     ans+=max(zer,green-1);
     else ans+=green;
     }
     if(s[j]=='G')
     {
     if((i+j)%2==0&&s[(i+j)/2]=='R')
     ans+=max(zer,red-1);
     else ans+=red;
     
     }
     }
     

    if(s[j]=='R')
    red++;
    if(s[j]=='B')
    blue++;
    if(s[j]=='G')
    green++;
   
  }

}cout<<ans<<endl;

}
 
 