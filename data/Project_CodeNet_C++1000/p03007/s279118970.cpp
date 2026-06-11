#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	vector<string> sv;
	rep(i, n) cin >> a.at(i);
	sort(a.begin(), a.end());
	vector<int> p, m;
	p.push_back(a.at(n-1));
	m.push_back(a.at(0));
	for(int i = 1; i < n-1; i++){
		int b = a.at(i);
		if(b < 0) m.push_back(b);
		else p.push_back(b);
	}
	rep(i, n-1){
		if(p.size() != 1){
			sv.push_back(to_string(m.back()) + " " + to_string(p.back()));
			m.back() -= p.back();
			p.pop_back();
		}else{
			sv.push_back(to_string(p.back()) + " " + to_string(m.back()));
			p.back() -= m.back();
			m.pop_back();
		}
	}
	cout << p.back() << endl;
	for(auto itr = sv.begin(); itr != sv.end(); itr++){
		cout << *itr << endl;
	}
	
	
	return 0;
}