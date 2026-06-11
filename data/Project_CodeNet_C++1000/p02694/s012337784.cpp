

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;



int main() {
	ll x;
	cin >> x;

	unsigned long long c = 100;


	
	int cnt = 0;
	while (c < x) {
		cnt++;
		c = c + c /100;
		

	}

	cout << cnt << endl;

}