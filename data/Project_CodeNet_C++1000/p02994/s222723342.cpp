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



    ll n,l;


    cin>>n>>l;

    ll sum=0;

    ll ara[n+2],t=0,mn=1000,ans=0;

  for(ll i=1;i<=n;i++)
  {
      ara[i]=i+l-1;
      sum+=ara[i];

      t=abs(ara[i]-0);

      if(t<mn)
      {
          mn=t;

          ans=ara[i];

      }

  }



 //for(ll i=1;i<=n;i++)cout<<ara[i]<<" ";cout<<endl;



 cout<<sum-ans<<endl;











}
