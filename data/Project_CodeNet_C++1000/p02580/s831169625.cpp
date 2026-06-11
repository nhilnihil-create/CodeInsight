#include <bits/stdc++.h>
using namespace std;

// #define int long long

int N, M, T;

int main(){
	cin >> N >> M >> T;
	unordered_map < int, int > row, col;
	set < pair < int, int > > loc; 
	int rmax = 0, cmax = 0;
	while (T--){
		int A, B; cin >> A >> B;
		A -= 1; B -= 1;
		row[A] += 1;
		col[B] += 1;
		loc.insert({A, B});
		if (row[A] > rmax)
			rmax = row[A];
		if (col[B] > cmax)
			cmax = col[B];
	}	
	int fr = 0, fc = 0;
	for (auto x : row) fr += (x.second == rmax);
	for (auto y : col) fc += (y.second == cmax);

	// cout << rmax << " " << cmax;
	// cout  << "\n\n";
	// for (auto r : row) cout << r.first << " " << r.second << "\n";
	// cout << "\n\n";
	// for (auto r : col) cout << r.first << " " << r.second << "\n";
	// cout << "\n\n";

	int ct = 0;
	for (auto l : loc){
		if (row[l.first] == rmax && col[l.second] == cmax){
			ct += 1;
		}
	}
	// cout << ct << "\n";

	cout << rmax + cmax - (ct == fr*fc) << "\n";


}

