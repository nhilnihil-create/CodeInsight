#include <bits/stdc++.h>
	
using namespace std;
inline void FAST_IO(){ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);}

template<class F, class S> ostream& operator<<(ostream& os, pair<F, S> &p) {
	os << "(" << p.first << "," << p.second << ")";
	return os;
}

template<class T, class S> ostream& operator<<(ostream& os, map<T, S> &v) {
	os << "{";
	for(auto &i : v) cout << "{" << i.first << "," << i.second << "}";
	os << "}";
	return os;
}

template<class T> ostream& operator<<(ostream& os, set<T> &v) {
	os << "{";
	for(auto &i : v) cout << i << ",";
	os << "}";
	return os;
}
 
template<class T> ostream& operator<<(ostream& os, vector<T> &v) {
	os << "[";
	if(v.size()) os << v[0];
	for(int i = 1; i < v.size(); ++i) os << "," << v[i];
	os << "]";
	return os;
}

/*----------------------------------------------------------------------------*/

int main (){
	// FAST_IO();

	int in[3][3];

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> in[i][j];			
		}
	}

	int n;
	cin >> n;

	while(n-->0) {
		int x;
		cin >> x;

		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (in[i][j] == x) {
					in[i][j] = 0;
				}			
			}
		}	
	}

	for (int i = 0; i < 3; ++i) {
		int sum = 0;
		for (int j = 0; j < 3; ++j) sum += in[i][j];
		if (!sum) {
			cout << "Yes" << endl;
			return 0;
		} 
	}


	for (int j = 0; j < 3; ++j) {
		int sum = 0;
		for (int i = 0; i < 3; ++i) sum += in[i][j];
		if (!sum) {
			cout << "Yes" << endl;
			return 0;
		} 
	}

	int da = 0, db = 0;
	for (int i = 0; i < 3; ++i) {
		da += in[i][i];
		db += in[2-i][i];
	}

	if (!da || !db) {
		cout << "Yes" << endl;
		return 0;
	} 

	cout << "No" << endl;

	return 0;
}
