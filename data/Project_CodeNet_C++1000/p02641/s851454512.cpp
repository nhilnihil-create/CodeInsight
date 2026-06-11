#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> p;
 
signed main(){
	int X, N;
	cin >> X >> N;
	p = vector<ll>(N);
	for(int i = 0; i < N; i++){
		cin >> p.at(i);
	}

	for(int i = 0; i <= 100; i++){
		if(find(p.begin(), p.end(), X-i) == p.end()){
			cout << X-i << endl;
			return 0;
		}else if(find(p.begin(), p.end(), X+i) == p.end()){
			cout << X+i << endl;
			return 0;
		}
	}
 
	return 0;
}