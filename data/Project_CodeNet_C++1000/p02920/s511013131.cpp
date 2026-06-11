#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

int N;
long long int S[500005];

multiset<long long int, greater<long long int> >  G, R;
int M;


long long int INF = 99999999999;
int main(void) {

	cin >> N;

	for (int i = 1; i <= (1 << N); i++) {
		cin>>S[i];
	}

	M = 1 << N;
	for (int i = 1; i <= M; i++) {
		R.insert(S[i]);
	}

	auto it = R.begin();
	G.insert(*it);
	R.erase(it);

	R.insert(-INF);
	vector<long long int >V;

	for (int i = 1; i <= N; i++) {
		V.clear();
		auto it = R.begin();
		for (auto y : G) {
			while (y <= (*it)) { it++; }
			if (*it == -INF) { cout << "No" << endl; return 0; }
			V.push_back(*it);
			it = R.erase(it);
		}
		for (auto h : V) { G.insert(h); }
		//cout << " --- G: "; for (auto y : G) { cout << " " << y; }cout << endl;
		//cout << " --- R: "; for (auto y : R) { cout << " " << y; }cout << endl;

	}



	//cout << " --- G: "; for (auto y : G) {cout <<" " <<  y;}cout << endl;
	//cout << " --- R: "; for (auto y : R) {cout <<" " << y; }cout << endl;

	cout << "Yes" << endl;

	return 0;
}