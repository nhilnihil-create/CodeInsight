#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <stack>
#include <string>
#include <algorithm> 
#include <set>
#include <sstream>
#include <bit>
#include <bitset>
#include <cstdint>
#include <iomanip>
#include <queue>
#include <initializer_list>
#include <stdio.h>
typedef long long int ll;
using namespace std;
int main() {
	ll H; cin >> H;
	ll num = 0;
	ll ans = 0;
	while (H > 0) {
		H /= 2;
		num++;
	}
	ans = pow(2, num)-1;
	cout << ans << endl;
}