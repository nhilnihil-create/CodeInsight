#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

#define pb push_back
#define mp make_pair

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef unsigned long long ull;
typedef long long ll;

int main() {
	ull H, W;
	cin >> H >> W;
	
	if (H == 1 || W == 1) {
		cout << 1;
	} else {
		cout << (H*W+1)/2;
	}

	cout << endl;
  return 0;
}