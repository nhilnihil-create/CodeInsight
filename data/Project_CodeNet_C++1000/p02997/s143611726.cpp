#include <bits/stdc++.h>
using ll = long long;
using namespace std;
using Graph = vector<vector<ll>>;

int main(){
  int n; cin>>n;
  int k; cin>>k;
  if (k > (n-2)*(n-1)/2)
  {
    cout << -1 << endl;
    return 0;
  }
  
  vector<pair<int,int>> e;
  for (size_t i = 2; i <= n; i++)
  {
    pair<int,int> tmp;
    tmp = make_pair(1,i);
    e.push_back(tmp);
  }
  int rem = (n-2)*(n-1)/2 - k;
  int i = 2;
  int j = 3;
  for (size_t _ = 0; _ < rem; _++)
  {
    e.push_back({i,j});
    j++;
    if (j>n)
    {
      i++;
      j = i+1;
    }
  }

  //out
  cout << e.size() << endl;
  for (auto &&i : e)
  {
    cout << i.first << ' ' << i.second << endl;
  }
   
  
}