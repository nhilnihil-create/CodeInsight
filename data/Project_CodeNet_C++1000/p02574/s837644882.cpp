#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define _h cout<<"here"<<endl;
#define fill(a,v) memset(a,v,sizeof(a));
#define all(v) v.begin(),v.end()
#define rep(i,n) for(int i=0;i<n;i+=1)
#define prd(a,n) rep(i,n) cout<<a[i]<<" \n"[i==n-1];// printf("%s\n"," " );
#define ff first
#define ss second
#define pu push_back
const int inf = 1e9+10;
const ll INF = 2e18+10;
const int Mod = 1e9+7;
const int MAXN = 1000010;
const int N=1e6+10;
const int M=210;
const int M1=1e9+7;
const int M2=1e9+9;
const int base=131;
int n,cnt[N],g=0;
vector<int> a;
int main()
{
  ios::sync_with_stdio(0), cin.tie(0); cout.tie(0);
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;
    cin>>x;
    g=__gcd(g,x);
    if(x==1) continue;
    a.push_back(x);
    cnt[x]++;
  }
  if(a.size()==0)
  {
    cout<<"pairwise coprime"<<endl;
    return 0;
  }
  int flag=0;
  for(int i=2;i<N;i++)
  {
    if(cnt[i]>1)
    {
      flag=1;
      break;
    }
  }
  if(flag)
  {
    if(g==1) cout<<"setwise coprime"<<endl;
    else cout<<"not coprime"<<endl;
  }
  else
  {
    set<int> s;
    for(int i=0;i<a.size();i++) s.insert(a[i]);
    auto it1=s.end();
    it1--;
    int mx=(*it1);
    for(int i=2;i<=mx;i++)
    {
      int cnt=0;
      for(int j=i;j<=mx;j+=i)
      {
        auto it=s.find(j);
        if(it!=s.end())
        {
          cnt++;
        }
        if(cnt>1)
        {
          if(g==1) cout<<"setwise coprime"<<endl;
          else cout<<"not coprime"<<endl;
          return 0;
        }
      }
    }
    cout<<"pairwise coprime"<<endl;
  }
  return 0;
}
