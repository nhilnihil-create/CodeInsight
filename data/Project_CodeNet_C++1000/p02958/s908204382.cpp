#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> p, p_sorted;

signed main(){
	int N;
	cin >> N;
	p = p_sorted = vector<int>(N);
	for(int i = 0; i < N; i++){
		cin >> p.at(i);
	}
	p_sorted = p;
	sort(p_sorted.begin(), p_sorted.end());
	int err = 0;
	for(int i = 0; i < N; i++){
		if(p.at(i) != p_sorted.at(i)){
			++err;
		}
	}
	if(err <= 2){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
 
	return 0;
}