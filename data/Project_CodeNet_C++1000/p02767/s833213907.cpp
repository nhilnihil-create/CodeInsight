#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> x(n);
  int ans=1000000000;


  for(int i=0; i<n; i++)
  {
    cin >> x.at(i);
  }

  sort(x.begin(), x.end());

  for(int i=x.at(0); i<=x.at(x.size()-1); i++)
  {
    int tmp=0;
    for(int j=0; j<n; j++)
    {
      tmp+=(x.at(j)-i)*(x.at(j)-i);
    }
    ans=min(ans, tmp);
  }

  cout << ans << endl;
}