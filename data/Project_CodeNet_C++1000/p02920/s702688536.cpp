#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  multiset <int> s;
  for(int i=0,x;i<(1<<n);i++)
  {
      cin>>x;
      s.insert(-x);
  }
  vector <int> v;
  v.push_back(*s.begin());
  s.erase(s.begin());
  for(int i=0;i<n;i++)
  {
      vector <int> tmp;
        for(int j=0;j<v.size();j++)
        {
            auto idx = s.upper_bound(v[j]);
            if(idx==s.end())
            {
                cout<<"No\n";
                return 0;
            }
            tmp.push_back((*idx));
            s.erase(idx);
        }
        for(int j=0;j<tmp.size();j++)
            v.push_back(tmp[j]);
        sort(v.begin(),v.end());
  }
  cout<<"Yes\n";
  return 0;
}
