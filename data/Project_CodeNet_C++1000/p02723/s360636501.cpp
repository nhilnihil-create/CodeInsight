#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES
#include <cmath>
//  long long MOD=1000000007;
vector<int> t(4*100001);
vector<int> t1(4*100001);
long long binary_exp(long long a,long long b)
{
  long long ans=1;
  while(b>0)
  {
    if(b&1)
    {
      ans=(ans*a);
    }
    a=(a*a);
    b=b>>1;
    if(ans>1e18)
    {
      return 1e18+1;
    }
  }
  return ans;
}
// long long gcd(long long a,long long b)
// {
//   if(b>a)
//   {
//     return gcd(b,a);
//   }
//   if(b==0)
//   {
//     return a;
//   }
//   else
//   {
//     return gcd(b,a%b);
//   }
// }
// class comp{
// public:
//     bool operator()(pair<long long ,long long > a,pair<long long ,long long > b)
// {
//   if(a.first>b.first)
//   {
//     return false;
//   }
//   else if(a.first==b.first && a.second<b.second)
//   {
//     return false;
//   }
//   else
//   {
//     return true;
//   }
//  }
// };

// void buildseg(long long  x,long long  l,long long  r,vector<int> &a)
// {
//   if(l==r)
//   {
//     t[x]=a[l];
//   }
//   else
//   {
//     long long  mid=(l+r)/2;
//     buildseg(2*x+1,l,mid,a);
//     buildseg(2*x+2,mid+1,r,a);
//     t[x]=t[2*x+1]+t[2*x+2];
//   }
// }
// long long  sum(long long  x,long long  l1,long long  r1,long long  l,long long  r)
// {
// //  cout<<l1<<" "<<r1<<" "<<l<<" "<<r<<" "<<"u"<<endl;
//   if(l>r)
//   {
//     return 0;
//   }
//   else if(l1==l && r1==r)
//   {
//     return t[x];
//   }
//   else
//   {
//     long long  mid=(l1+r1)/2;
//
//     return sum(2*x+1,l1,mid,l,min(r,mid))+sum(2*x+2,mid+1,r1,max(l, mid+1),r);
//   }
// }
// void buildseg1(long long  x,long long  l,long long  r,vector<int> &a)
// {
//   if(l==r)
//   {
//     t[x]=a[l];
//   }
//   else
//   {
//     long long  mid=(l+r)/2;
//     buildseg(2*x+1,l,mid,a);
//     buildseg(2*x+2,mid+1,r,a);
//     t[x]=max(t[2*x+1],t[2*x+2]);
//   }
// }
// long long  sum1(long long  x,long long  l1,long long  r1,long long  l,long long  r)
// {
// //  cout<<l1<<" "<<r1<<" "<<l<<" "<<r<<" "<<"u"<<endl;
//   if(l>r)
//   {
//     return -1;
//   }
//   else if(l1==l && r1==r)
//   {
//     return t[x];
//   }
//   else
//   {
//     long long  mid=(l1+r1)/2;
//
//     return max(sum1(2*x+1,l1,mid,l,min(r,mid)),sum(2*x+2,mid+1,r1,max(l, mid+1),r));
//   }
// }
// void update(long long x,long long l,long long r,char value,long long  pos,string &a)
// {
//   if(l==r)
//   {
//
//     t[x][a[pos]-'a']=max(0,t[x][a[pos]-'a']-1);
//     t[x][value-'a']++;
//       a[pos]=value;
//   }
//   else
//   {
//     long long  mid=(l+r)/2;
//     if(mid>=pos)
//     {
//       update(2*x+1,l,mid,value,pos,a);
//     }
//     else
//     {
//         update(2*x+2,mid+1,r,value,pos,a);
//     }
//     vector<long long > v(26,0);
//     for(long long i=0;i<26;i++)
//     {
//       if(t[2*x+1][i]>0)
//       {
//         v[i]+=t[2*x+1][i];
//       }
//       if(t[2*x+2][i]>0)
//       {
//         v[i]+=t[2*x+2][i];
//       }
//     }
//     t[x]=v;
//   }
// }
// void prdoubleseg(long long  n)
// {
//   for(long long  i=0;i<4*n;i++)
//   {
//     cout<<t[i]<<" ";
//   }
//   cout<<endl;
// }
// void dfs(double x,  vector<vector<double> > &adj,vector<set<double> > &v,double &count,vector<double> &vis)
// {
//   v[x].insert(count);
//   vis[x]=1;
//   for(auto i : adj[x])
//   {
//     if(vis[i]==0)
//     {
//       vis[i]=1;
//       dfs(i,adj,v,count,vis);
//     }
//   }
// }
// void bfs(long long  i,long long  j,vector<vector<long long > > &vis,vector<vector<long long > > &b,vector<vector<long long > > adj)
//   {
//     queue<pair<long long ,long long > > q;
//     q.push({i,j});
//     vis[i][j]=1;
//     b[i][j]=0;
//     long long  n=b[0].size();
//     while(!q.empty())
//     {
//        pair<long long ,long long > k=q.front();
//       q.pop();
//        long long  u=k.first,p=k.second;
//        if(u<n-1){
//       if(vis[u+1][p]==0 && adj[u+1][p]==0)
//       {
//           q.push({u+1,p});
//           b[u+1][p]=b[u][p]+1;
//           vis[u+1][p]=1;
//
//       }
//       }
//       if(p<n-1){
//       if(vis[u][p+1]==0 && adj[u][p+1]==0)
//       {
//           q.push({u,p+1});
//           b[u][p+1]=b[u][p+1]+1;
//           vis[u+1][p]=1;
//       }
//      }
//      if(u>0){
//     if(vis[u-1][p]==0 && adj[u-1][p]==0)
//     {
//         q.push({u-1,p});
//         b[u-1][p]=b[u][p]+1;
//         vis[u-1][p]=1;
//
//     }
//     }
//     if(p>0){
//    if(vis[u][p-1]==0 )
//    {
//        q.push({u,p-1});
//        b[u][p-1]=b[u][p]+1;
//        vis[u][p-1]=1;
//
//    }
//    }
//     }
//   }
// void bfs(vector<long long > s,vector<vector< long long  > >adj,vector<long long > &d,vector<long long > &vis)
// {
//   queue<long long > q;
//   for(long long  i=0;i<s.size();i++)
//   {
//     q.push(s[i]);
//     vis[s[i]]=1;
//     d[s[i]]=0;
//   }
//   while(!q.empty())
//   {
//     long long  t=q.front();
//     q.pop();
//     for(auto i: adj[t])
//     {
//       if(vis[i]==0)
//       {
//         d[i]=d[t]+1;
//         q.push(i);
//         vis[i]=1;
//       }
//     }
//   }
// }
// void shortest(long long  s, vector<vector<pair<long long ,long long > > > adj,vector<long long > &d,vector<long long > &pref)
// {
//   priority_queue<pair<long long ,long long > ,vector<pair<long long ,long long > >, greater<pair<long long ,long long > > > q;
//   d[s]=0;
//   q.push({0,s});
//   while(!q.empty())
//   {
//     pair<long long ,long long > temp=q.top();
//     q.pop();
//     long long  t=temp.second;
//     for(auto i: adj[t])
//     {
//       long long  w=i.second;
//       long long  p=i.first;
//       if(d[p]>(d[t]+w))
//       {
//         d[p]=d[t]+w;
//         q.push({d[p],p});
//         pref[p]=t;
//       }
//     }
//   }
//
// }
int maxsub(int l,int r,vector<int> &a)
{
  int max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = l; i <= r; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}
int  main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long T;
  T=1;
  while(T--)
  {
    string s;
    cin>>s;
    if(s[2]==s[3] && s[4]==s[5])
    {
      cout<<"Yes"<<endl;
    }
    else
    {
      cout<<"No"<<endl;
    }

  }

   return 0;
}
