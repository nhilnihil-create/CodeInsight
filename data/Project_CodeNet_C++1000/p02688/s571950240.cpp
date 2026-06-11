#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,k;
	cin >> n >> k;
	int dnum;
	int anum;
	vector<int> HaveTreat(n);
	for(int i = 0; i < k; i++){
		cin >> dnum;
		for(int j = 0; j < dnum; j++){
			cin >> anum;
			HaveTreat[anum-1]++;
		}
	}
	int Trick = 0;
	for(int i = 0; i < n; i++){
		if(HaveTreat[i] == 0){
			Trick++;
		}
	}
	cout << Trick;
}