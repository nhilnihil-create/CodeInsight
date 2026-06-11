#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const double pi=acos(-1);





int main() 
{
  ll N; cin>>N;
  vector<string> s(N);
  rep(i,N)
  {
    string hoge; cin>>hoge;
    sort(hoge.begin(),hoge.end());
    s.at(i)=hoge;
  }
  sort(s.begin(),s.end());
  ll ans=0;
  ll count=0;
  rep(i,N)
  {
    if(i==0) {count++; continue;}
    if(s.at(i)==s.at(i-1)) {count++; continue;}
    ans+=count*(count-1)/2;
    count=1;
  }
  ans+=count*(count-1)/2;
  
  cout<<ans<<endl;
  return 0;
}
