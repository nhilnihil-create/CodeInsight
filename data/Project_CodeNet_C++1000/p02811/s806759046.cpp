#include "bits/stdc++.h"

using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long

int main()
{
  IOS;
  int k, x;
  cin >> k >> x;
  k*=500;
  if (k>=x)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
