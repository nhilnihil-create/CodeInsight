#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
	
	int n; cin>>n;
	vector<int> a(n);
	for(auto &i:a) cin>>i;
	ll sum{};
	for(int i=0; i<n; i++){
		sum += a.at(i);
	}
	int b{-1};
	ll sum2{};
	for(int i=0; i<n; i++){
		sum2 += a.at(i);
		if(sum2*2>sum) {
			sum2 -= a.at(i);
			b = i;
			break;
		}
	}
	cout << abs( a.at(b)-abs( sum2-( sum-(sum2+a.at(b)) ) ) ) << endl;
	
	
}

