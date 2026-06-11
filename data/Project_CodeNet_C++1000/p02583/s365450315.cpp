#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main()
{
  int n; cin >> n;

  vector<int> v(n);
  for(int i=0; i<n; ++i) cin >> v.at(i);

  if(n<3){
    cout << 0 << endl;
    return 0;
  }

  int sum=0;
  for(int i=0; i<n; ++i)
    for(int j=i+1; j<n; ++j)
      for(int k=j+1; k<n; ++k)
      {
        if(v[i]==v[j] || v[j]==v[k] || v[k]==v[i]){continue;}
          if(v[i]+v[j] > v[k] && v[j]+v[k] > v[i] && v[k]+v[i] > v[j]) ++sum;
      }
  cout << sum << endl;
}