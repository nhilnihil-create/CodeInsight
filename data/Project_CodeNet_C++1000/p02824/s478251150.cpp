#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
int main()
{
  ll n,m,v,p;cin>>n>>m>>v>>p;
  vector<ll> a(n);
  int i,j;
  rep(i,n)cin>>a[i];
  sort(all(a));
  reverse(all(a));
  int left=0;
  int right=n-1;
  int lasok=0;
  while(left<=right)
  {
    int cent=(left+right)/2;
    ll base=a[cent]+m;
    vector<ll> b(n-1);//sorted
    rep(j,n-1)
    {
      if(j<cent)b[j]=a[j];
      else b[j]=a[j+1];
    }
    rep(j,p-1)b[j]+=m;
    ll jug=m*(v-p);
    if(base<b[p-1])
    {
      right=cent-1;
    }
    else
    {
      int now=n-2;
      while(jug>0&&now>=p-1)
      {
        jug-=min(base-b[now],m);
        b[now]+=min(base-b[now],m);
        now--;
      }
      if(jug>0)
      {
        right=cent-1;
      }
      else
      {
        lasok=cent;
        left=cent+1;
      }
    }
  }
  cout<<lasok+1<<endl;
}
