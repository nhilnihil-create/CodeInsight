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

int main() { 

int h,w,m,x,y;
set<pair<int,int> > s;
cin>>h>>w>>m;
int row[h+1]={0};
int col[w+1]={0};

unordered_map<pair<int,int> , int ,hash_pair> hap;
for(int i=0;i<m;i++)
{
  cin>>x>>y;
 // hap[{x,y}]=1;
  s.insert({x,y});
  row[x]++;
  col[y]++;
}

int ans=0,ma=0;
for(int i=1;i<=h;i++)
{
  //cout<<row[i]<<" ";
  ans=max(ans,row[i]);
}

for(int i=1;i<=w;i++)
{
  ma=max(ma,col[i]);
}

vector<int> candr;
vector<int> candc;
for(int i=1;i<=h;i++)
  if(ans==row[i])
    candr.pb(i);

for(int i=1;i<=w;i++)
  if(ma==col[i])
    candc.pb(i);


ll k=ans+ma-1,flag=1;
for(int i=0;i<candr.size();i++)
  for(int j=0;j<candc.size();j++)
  {
    if(s.find({candr[i],candc[j]})==s.end())
    {
      k++;
      goto l1;
    }
    if(flag==0)
      break;
  }


l1:
cout<<k;


return 0;
}
