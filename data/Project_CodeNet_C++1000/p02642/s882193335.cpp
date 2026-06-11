using namespace std;
#include <bits/stdc++.h>
#define FASTIO                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL);
#define ll long long
#define debug(x) cout << #x << " = " << x << endl
int n;
set<int> elements;
int fre[1000001];
int arr[1000001];
bool check(int val)
{
  if (val == 1)
  {
    if (fre[1] > 1)
      return false;
    else
      return true;
  }
  if(fre[1]>0)
  return false;
  for (int i = 2; i <= sqrt(val); i++)
  {
    if (val % i == 0)
    {
      if (fre[i] > 0)
      {
        cerr << i << " " << fre[i] << endl;
        return false;
      }
      if (val / i != i)
      {
        if (fre[val / i] > 0)
        {
          cerr << val / i << " " << fre[val / i] << endl;
          return false;
        }
      }
    }
  }
  cerr<<1<<endl;
  return true;
}
void solve()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    elements.insert(arr[i]);
    fre[arr[i]]++;
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    int value = arr[i];
    if (fre[value] > 1)
      continue;
    else
    {
      if (check(arr[i]))
        ans++;
    }
  }
  cout << ans << endl;
  //check(16);
}
int main()
{
  FASTIO
  long long int t = 1;
  //cin>>t;
  while (t--)
    solve();
  return 0;
}
