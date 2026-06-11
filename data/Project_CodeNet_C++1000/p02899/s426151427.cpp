#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
	int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < (n); ++i) 
  	cin >> a[i];
  int ans[n];
  for (int i = 0; i < (n); ++i) 
  	ans[a[i]-1] = i+1;
  for (int i = 0; i < (n); ++i) 
	cout << ans[i] << endl;
  return 0;
}