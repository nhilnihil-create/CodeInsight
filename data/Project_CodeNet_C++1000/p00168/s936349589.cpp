#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <list>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <math.h>

#define PREP(i, m, n) for(int i = m; i < n; i++)
#define MREP(i, m, n) for(int i = m - 1; i >= n; i--)

#define rep(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define all(v) v.begin(), v.end()
#define rev(v) v.rbegin(), v.rend()
#define X first
#define Y second
#define MP make_pair
#define PB push_back

using namespace std;



int main(){
	vector<int>  stairs;
	stairs.push_back(1);
	stairs.push_back(1);
	stairs.push_back(2);
	
	for(int i = 3; i < 31; i++){
		int tmp = stairs[i - 1] + stairs[i - 2] + stairs[i - 3];
		stairs.push_back(tmp);
	}

	int n = 0;
	while(cin >> n && n != 0){
		int tmp = 0;
		if(stairs[n] / 10 == 0) tmp = 1;
		else tmp = stairs[n] / 10;
		if(tmp % 365 == 0){
			cout << tmp / 365 << endl;
		}
		else{
			cout << tmp / 365 + 1 << endl;
		}
	}

	return 0;
}