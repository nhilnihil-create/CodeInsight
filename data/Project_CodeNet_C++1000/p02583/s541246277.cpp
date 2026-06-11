// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
int n;
int main()
{
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)cin >> a[i];
  sort(all(a));
  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = i+1; j < n; j++)
      for (int k = j+1; k < n; k++)
      {
        if (a[i] == a[j])continue;
        if (a[i] == a[k])continue;
        if (a[j] == a[k])continue;
        if (a[i] + a[j] > a[k])ans++;
      }
  cout << ans << '\n';
}
