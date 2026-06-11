#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <string>
#include <algorithm> 
#include <set>
#include <sstream>
#include <bit>
#include <bitset>
#include <iomanip>
#include <queue>
typedef long long int ll;
using namespace std;
int main() {
	string S; cin >> S;
	for (int i = 0; i < S.size(); i++) {
		S[i] = 'x';
	}
	cout << S << endl;
}