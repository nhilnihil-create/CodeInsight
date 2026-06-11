#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	ll n;
	cin >> n;
	vector<P> ab(n);
	rep(i,n) {
		cin >> ab[i].second >> ab[i].first;
	}
	sort(ab.begin(),ab.end());
	ll time = 0;
	int ju = 1;
	for(auto p:ab){
		time += p.second;
		if(time > p.first){
			ju = 0;
			break;
		}
	}
	if(ju) cout << "Yes" << endl;
	else cout << "No" << endl;
}