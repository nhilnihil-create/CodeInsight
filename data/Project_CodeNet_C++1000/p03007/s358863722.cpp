#include <bits/stdc++.h>
using namespace std;
using Int = int_fast64_t;

Int n;
vector<Int> a;
using P = pair<Int, Int>;
vector<P> v;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	a.resize(n);
	for(auto &i:a) cin >> i;
	Int mi = 1e9, ma = -1e9, imi = -1, ima = -1;
	for(size_t i=0; i<a.size(); ++i){
		if(a[i] > ma){
			ma = a[i];
			ima = i;
		}
	}
	for(size_t i=0; i<a.size(); ++i){
		if(i != ima && a[i] < mi){
			mi = a[i];
			imi = i;
		}
	}
	for(size_t i=0; i<a.size(); ++i){
		if(a[i] >= 0 && i != imi && i != ima){
			v.push_back(P(a[imi], a[i]));
			a[imi] -= a[i];
		}
	}
	for(size_t i=0; i<a.size(); ++i){
		if((a[i] < 0 || i == imi) && i != ima){
			v.push_back(P(a[ima], a[i]));
			a[ima] -= a[i];
		}
	}
	cout << a[ima] << "\n";
	for(auto i:v) cout << i.first << " " << i.second << "\n";
}