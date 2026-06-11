#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const double pi=acos(-1);


int N,M,Q;
vector<vector<int>> A(0);

void make(vector<int> a,int n)
{
  if(n==N) {A.push_back(a); return;}
  int l=a.at(n-1);
  for(int i=l;i<=M;i++)
  {
    auto b=a;
    b.push_back(i);
    make(b,n+1);
  }
}  



int main() 
{
  cin>>N>>M>>Q;
  rep(i,M)
  {
    make({i+1},1);
  }  
  /*
  for(auto a:A)
  {
    for(auto w:a)
    {
      cout<<w<<" ";
    }
    cout<<endl;
  }
  */
  
  vector<int> a(Q);
  vector<int> b(Q);
  vector<int> c(Q);
  vector<int> d(Q);
  rep(i,Q)
  {
    cin>>a.at(i)>>b.at(i)>>c.at(i)>>d.at(i);
    a.at(i)--;
    b.at(i)--;
  }
  
  int ans=0;
  for(auto hoge:A)
  {
    int sum=0;
    rep(i,Q)
    {
      if(hoge.at(b.at(i))-hoge.at(a.at(i))==c.at(i))
      {
        sum+=d.at(i);
      }
    }
    ans=max(sum,ans);
  }
  
  cout<<ans<<endl;
  
  return 0;
}

