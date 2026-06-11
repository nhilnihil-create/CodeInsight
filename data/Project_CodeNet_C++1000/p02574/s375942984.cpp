#include <iostream> 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mk make_pair
#define MAX 1000001
ll prime[MAX];
#define FAST           ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define gcd __gcd
ll rec(vector<vector<ll> >& dp,vector<ll>& arr,int n,int i,int k,int w)
{
  ll ans=0;
  if(i>=n)
    return 0;

  if(dp[i][k]!=-1)
    return dp[i][k];


  if(k!=0)
  ans=max(rec(dp,arr,n,i+1,w,w),arr[i]+rec(dp,arr,n,i+1,k-1,w));
  else
  ans=max(rec(dp,arr,n,i+1,k,w),rec(dp,arr,n,i+1,w,w));

  return dp[i][k]=ans;

}

//ll t[400008];
// void build(vector<ll>& a, int v, int tl, int tr) {
//     if (tl == tr) {
//         t[v] = a[tl];
//     } else {
//         int tm = (tl + tr) / 2;
//         build(a, v*2, tl, tm);
//         build(a, v*2+1, tm+1, tr);
//         t[v] = max(t[v*2] ,t[v*2+1]);
//     }
// }

// ll maxi(int v, int tl, int tr, int l, int r) {
//     if (l > r) 
//         return 0;
//     if (l == tl && r == tr) {
//         return t[v];
//     }
//     int tm = (tl + tr) / 2;
//     return max(maxi(v*2, tl, tm, l, min(r, tm)) ,maxi(v*2+1, tm+1, tr, max(l, tm+1), r));
// }



// void update(int v, int tl, int tr, int pos, ll new_val) {
//     if (tl == tr) {
//         t[v] = new_val;
//     } else {
//         int tm = (tl + tr) / 2;
//         if (pos <= tm)
//             update(v*2, tl, tm, pos, new_val);
//         else
//             update(v*2+1, tm+1, tr, pos, new_val);
//         t[v] = max(t[v*2] ,t[v*2+1]);
//     }
// }


struct hash_pair {
   template <class T1, class T2>
   size_t operator()(const pair<T1, T2>& p) const{
      auto hash1 = hash<T1>{}(p.first);
      auto hash2 = hash<T2>{}(p.second);
      return hash1 ^ hash2;
   }
};

ll rec(ll a[],ll first,ll last,int n)
{
  if(first>last)
    return 0;

  ll temp=1000000000;
  ll ind=0;
  for(ll i=first;i<=last;i++)
   {
    if(temp>a[i])
    {
      temp=a[i];
      ind=i;
    }
   }
   for(ll i=first;i<=last;i++)
    a[i]-=temp;


return min(last-first+1,(rec(a,first,ind-1,n)+rec(a,ind+1,last,n)+temp));

}
int temp[1000002]={0};

void sieve()
{
  temp[1]=1;
  for(int i=2;i<1000002;i++)
  {
    if(temp[i]==0)
    { temp[i]=i;
      for(int j=i*2;j<1000002;j+=i)
      { 
        if(temp[j]==0)
        temp[j]=i;
      }
    }
  }

}


int main() { 
int n;
cin>>n;
int a[n];

int k;
sieve();

unordered_map<int,int> over;
int flag=0,dum;

for(int i=0;i<n;i++)
{  
   cin>>a[i];
  
  dum=a[i];
  unordered_map<int,int> h;
  while(dum>1)
  {
    if(over[temp[dum]]!=0 && h[temp[dum]]!=1 )
      flag=1;

    h[temp[dum]]=1;
    over[temp[dum]]=1;

    dum=dum/temp[dum];
  }


}

if(flag)
  k=0;
else
  k=2;


int j;
if(k==0)
{  for(int i=0;i<n;i++)
  {
    if(i==0)
      j=a[i];
    else
      j=gcd(j,a[i]);
    
  }
  if(j==1)
    k=0;
  else
    k=1;

}

switch(k)
{
  case 2:cout<<"pairwise coprime";
  break;
  case 0:cout<<"setwise coprime";
  break;
  case 1:cout<<"not coprime";
}


return 0;
}
