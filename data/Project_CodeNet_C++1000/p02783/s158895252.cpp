#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <stack>
#include <string>
#include <algorithm> 
#include <set>
#include <sstream>
#include <list>
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
	int H, A; cin >> H >> A;
	int ans = H / A;
	if (H % A != 0)ans++;
	cout << ans << endl;

}