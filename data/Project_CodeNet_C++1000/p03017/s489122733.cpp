#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int N, A, B, C, D;
	cin >> N >> A >> B >> C >> D;
	A--;
	B--;
	C--;
	D--;

	string s;
	cin >> s;

	bool AtoC = true;
	int cnt = 0;
	for (int ii = A + 1; ii <= C; ++ii){
		if (s[ii] == '#'){
			cnt++;
		} else {
			cnt = 0;
		}
		if (cnt == 2){
			AtoC = false;
			break;
		}
	}

	bool BtoD = true;
	cnt = 0;
	for (int ii = B + 1; ii <= D; ++ii){
		if (s[ii] == '#'){
			cnt++;
		} else {
			cnt = 0;
		}
		if (cnt == 2){
			BtoD = false;
			break;
		}
	}

	bool BtoD2 = false;
	for (int ii = B; ii <= D; ++ii){
		if ( (s[ii-1] == '.') && (s[ii] == '.') && (s[ii+1] == '.') ){
			BtoD2 = true;
			break;
		}
	}

	bool OK = AtoC && BtoD;
	if (D < C){
		OK = OK && BtoD2;
	}

	if (OK){
		cout << "Yes" << "\n";
	} else {
		cout << "No" << "\n";
	}


	return 0;
}
