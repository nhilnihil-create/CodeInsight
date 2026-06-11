#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;




signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);  
  cout.tie(0);   

  #ifndef ONLINE_JUDGE
      if(fopen("INPUT.txt","r"))
      {
      freopen ("INPUT.txt" , "r" , stdin);
      freopen ("OUTPUT.txt" , "w" , stdout);
      }
    #endif  

  int n;
  cin>>n;
  multiset<int>s;
  int x;
  for(int i=0;i<(1<<n);i++)
  {
    cin>>x;
    s.insert(x);
  }  
  auto j=s.end();
  j--;

  vector<int>cur;
  cur.push_back(*j);
  s.erase(j);
  int cnt=n;
  while (cnt--)
  {
    vector<int>temp;
    for(auto i:cur)
    {
      auto j=s.lower_bound(i);
      if(j!=s.begin())
        j--;
      else
      {
        cout<<"No";
        return 0;
      }
      temp.push_back(*j);
      s.erase(j);
    }
    for(auto i:temp)
      cur.push_back(i);
  }
  
  cout<<"Yes";

}