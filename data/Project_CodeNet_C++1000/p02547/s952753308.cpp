#include <bits/stdc++.h>
#define ll long long
#define elif else if
#define endl "\n"
#define _  <<" "<<
#define eb(x) emplace_back(x)
#define maxelem(v) *max_element(v.begin(),v.end())
#define minelem(v) *min_element(v.begin(),v.end())
#define FOR(a,b) for(int i=int(a);i<int(b);++i)

using namespace std;

const int mod = 1e9+7;

void izlaz(string br)
{
  if(!br.size())
    exit(EXIT_SUCCESS);
  cout<<br;
  exit(EXIT_SUCCESS);

}

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int ans,x,y;
  bool f=0;
  ans=0;
  int test;
  cin>>test;
  while(test--)
  {
      cin>>x>>y;
      if(x==y)
      {
          ++ans;
          if(ans>=3)
             f=1;
      }
      else
        ans=0;
  }
  if(f)
    cout<<"Yes";
  else
    cout<<"No";



 return 0;
}
