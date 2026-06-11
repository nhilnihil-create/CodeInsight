#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vecll vector<long long>
#define vec2ll vector<vector<long long>>
#define vecbool vector<bool>
#define vecpairll vector<pair<long long,long long>>
#define forll(s,a,b) for(long long s = a;s < b;s++)
#define forllde(s,a) for(long long s = a;s > 0;s--)


int main()
{
  ll n, k, s;
  ll x = 1e9;
  cin >> n >> k >> s;
  if (s == x)
	x = 1;
  forll(i, 0, k)
	cout << s << " ";
  forll(i, k, n)
	cout << x << " ";
}
