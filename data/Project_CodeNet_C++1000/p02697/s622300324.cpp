#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<int, int>> bf;

void match_fighter(int l, int r){
	while(l < r){
		pair<int, int> p(l, r);
		bf.push_back(p);
		l++;
		r--;
	}
}

int main(){
	int n, m;
	cin >> n >> m;

	match_fighter(1, m);
	match_fighter(m+1, 2*m+1);

	for(int i=0; i<bf.size(); i++){
		cout << bf[i].first << ' ' << bf[i].second << endl;
	}
}
