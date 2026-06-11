#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rrep(i,n) for (int i = 1; i <= (n); i++)
using ll = long long;
using Graph = vector<vector<int>>;

int main() {
	float x;
	cin >> x;
	if(floor(ceil(x / 1.08) * 1.08)  == x){
		cout << ceil(x / 1.08) << endl;
	} else {
		cout << ":(" << endl;
	}	
 }
