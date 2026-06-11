/*
                  ,     \    /      ,
                 / \    )\__/(     / \
                /   \  (_\  /_)   /   \
           ____/_____\__\@  @/___/_____\____
          |             |\../|              |
          |              \VV/               |
          |        ------___-------         |
          |__________Chuta Dragon___________|
           |    /\ /      \\       \ /\    |
           |  /   V        ))       V   \  |
           |/     `       //        '     \|
           `              V                '
        */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastread() (ios_base:: sync_with_stdio(false),cin.tie(NULL))
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
void input(ll ara[],ll n)
{
    for(ll i=0; i<n; i++)
        cin>>ara[i];
}

#define eb emplace_back

int main()
{


    fastread();



    ll a,b,c,d;


    cin>>a>>b>>c>>d;

   ll g=__gcd(c,d);

   ll l=(c/g)*d;

   //cout<<g<<" "<<l<<endl;

   ll sum=(b/c)+(b/d)-(b/l);
 // cout<<sum<<endl;
   sum=b-sum;
   a--;

   ll ans=(a/c)+(a/d)-(a/l);
  ans=a-ans;
   cout<<sum-ans<<endl;






}
