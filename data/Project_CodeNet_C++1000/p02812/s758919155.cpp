#include "bits/stdc++.h"

using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long

int main()
{
  IOS;
  int n;
  string s;
  cin >> n >> s;
  int ans=0;
  for (int i=0; i<n; i++)
    {
      if (s.substr(i,3)=="ABC")
	ans++;
    }
  cout << ans << endl;
  return 0;
}
