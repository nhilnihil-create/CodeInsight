#include "bits/stdc++.h"

using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long

int main()
{
  IOS;
  int h, n;
  cin >> h >> n;
  int t=0;
  for (int i=0, x; i<n; i++)
    {
      cin >> x;
      t+=x;
    }
  if (t>=h)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
