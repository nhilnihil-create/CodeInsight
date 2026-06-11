#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdio>
#include <cmath>
#include <tuple>


using namespace std;
#define i64  long long

void solve(void)
{
  i64 N;
  cin>>N;
  multiset<i64,greater<i64>> s;
  vector<i64> b;
  i64 in;   
  for (i64 i = 0; i < (1<<N); i++)
  {
    cin>>in;
    s.insert(in);
  }

 
  b.push_back(*s.begin());
  s.erase(s.begin());
  for (i64 i = 0; i < N; i++)
  {
    for (i64 j = 0; j < (1<<i); j++)
    {
      auto si = s.upper_bound(b[j]);
      // cout<<*s.end()<<endl;
      //iteratorのendは最後の次
      if(si == s.end()){
        cout<<"No";
        return ;
      }
      b.push_back(*si);
      s.erase(si);
    }
  }

  cout<<"Yes";
  return;
  
}
int main(int argc, const char *argv[])
{

  solve();
  
  return 0;
}
