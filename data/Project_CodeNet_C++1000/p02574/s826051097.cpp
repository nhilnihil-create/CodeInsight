#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define mp make_pair
#define ll long long
#define pb push_back

void solve()
{

  int n;
  cin>>n;

  vector<int>v(n);

  int i,j;
  int maxi = INT_MIN;

  
  
  for(i=0;i<n;i++)
  {
      cin>>v[i];
      maxi = max(maxi, v[i]);
      
      
  }
  int gcd  = v[0];
  
  vector<int>sieve(maxi+1,-1);
  
  sieve[1] = 1;

  for(i=2;i<=maxi;i++)
  {
      if(sieve[i]!=-1)continue;

      for(j=i;j<=maxi;j=j+i)
      {
          if(sieve[j]==-1)
            sieve[j] = i;
      }
  }



  bool f = 1;

  map<int,int>m;

  for(auto it=v.begin();it!=v.end();it++)
  {
      int val = *it;
      gcd = __gcd(gcd, val);

      while(val>1)
      {
          int x = sieve[val];

          if(x==-1)
            break;
           m[x]++;

          while(val%x==0)
            val = val/x;
      }
  }
  
  for(auto it=m.begin();it!=m.end();it++)
  {
      if(it->second > 1)f=0;
  }

  if(f==1)
  {
      cout<<"pairwise coprime"<<endl;
      return;
  }
  if(gcd==1)
  {
      cout<<"setwise coprime"<<endl;
      return;
  }

  cout<<"not coprime"<<endl;
}

int main()
{

  int t = 1;
  //cin>>t;

  while(t--)
    solve();

  return 0;
}
