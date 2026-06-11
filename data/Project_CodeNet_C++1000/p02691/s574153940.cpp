#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int n; cin >> n;
	vector< int > v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
  int larr[n + 1];
  int rarr[n + 1];
  for(int i =  0; i < n; ++i){
  	larr[i] = i - v[i];
  	rarr[i] = i + v[i]; 
  }
  ll ans = 0;
  sort(rarr, rarr + n);
  for(int i = 0; i < n; ++i){
  	auto z = lower_bound(rarr,rarr + n,larr[i]);
  	auto y = upper_bound(rarr,rarr + n,larr[i]);
  	if(y - z > 0 && *z == larr[i]){
  		ans += (ll)(y - z);
  		//cout << i + 1 << '\n';
  	}
  }
  //cout << "==========" << '\n';
  cout << ans << '\n';
}