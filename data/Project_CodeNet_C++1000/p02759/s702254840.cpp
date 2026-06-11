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
  int n;
  cin >> n;
  if (n%2!=0)
    cout << (n/2)+1 << endl;
  else
    cout << n/2 << endl;
  return 0;
}
