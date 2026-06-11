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
  ll n, s=0, over, tmp=0;
  cin >> n;
  vecll a(n);
  forll(i, 0, n){
	cin >> a[i];
	s += a[i];
  }
  double m = (double)s / 2.0;
  forll(i, 0, n){
	tmp += a[i];
	if ((double)tmp > m){
	  over = i;
	  break;
	}
  }
  cout << (ll)(min(((double)tmp-m), (m - (double)(tmp - a[over]))) * 2) << endl;
}
