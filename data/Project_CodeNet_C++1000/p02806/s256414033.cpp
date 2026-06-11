#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<string,ll> P;

int main() {
	int n; cin>>n;
    vector<P> x(n);
  	for (int i=0; i<n; ++i) {
    	cin>>x[i].first>>x[i].second;
    }
  	string s; cin>>s;
  	int ans = 0;
  	bool sleep = false;
  	for (int i=0; i<n; ++i) {
      	if (sleep) ans += x[i].second;
    	if (x[i].first == s) sleep = true;
    }
  	cout<<ans<<endl;
  	return 0;
}
