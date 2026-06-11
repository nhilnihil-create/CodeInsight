//tanzim bin nasir
#include<bits/stdc++.h>
typedef long long ll;
#define ff first
#define ss second
using namespace std;
void fast()
{
ios::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
}
ll gcd(ll a,ll b)
{
    if(b==0)
    return a;
    else
    gcd(b,a%b);
}
ll lcd(ll a,ll b)
{
    return (a*b)/gcd(a,b);
}
int main()
{
    string a,b;
    cin>>a>>b;
    int j=0,ans=b.size(),sum=b.size();
    for(int i=0;i<=a.size()-sum;i++)
    {
      int k=i;
      int temp=0;
      for(int j=0;j<b.size();j++,k++)
      {
          if(a[k]==b[j])
            temp++;
          ans=min(ans,sum-temp);
      }
    }
    cout<<ans<<endl;
}

