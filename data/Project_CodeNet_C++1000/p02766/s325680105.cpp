#include "bits/stdc++.h"

using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define ll long long
#define li long int

#define pb push_back
#define m <i> map<int>
#define v <i> vector<int>

#define rep(i, n) for(int i=0; i<n; i++)

int main()
{
  IOS;
  int n, k;
  cin >> n >> k;
  int ans=0;
  while (n>0)
    {
      n/=k;
      ans++;
    }
  cout << ans << endl;
  return 0;
}
