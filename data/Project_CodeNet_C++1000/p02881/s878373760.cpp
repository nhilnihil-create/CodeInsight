#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const ll INF = 1000000000000000;

int main(){
	ll n;
	cin >> n;
	int time = sqrt(n);
	ll mx = INF;
	ll wa = 0;
	for(int i = 1; i <= time; i++){
		wa = 0;
		if(n%i != 0) continue;
		else{
			wa = i + n/i;
			mx = min(wa,mx);
		}
	}
	cout << mx -2 << endl;
}