#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vecll vector<long long>
#define vec2ll vector<vector<long long>>
#define vecpairll vector<pair<long long,long long>>
#define forll(s,a,b) for(long long s = a;s < b;s++)
#define forllde(s,a) for(long long s = a;s > 0;s--)

int main(){
  ll n;
  cin >> n;
  vecll a(n);
  forll(i, 0, n)
	cin >> a[i];
  ll x = a[n-1];
  
  forll (i, 0, n-1){
	x = x ^ a[i];
  }
  if (x == 0)
	cout << "Yes" << endl;
  else
	cout << "No" << endl;
}