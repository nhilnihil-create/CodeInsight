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
	int A, B; cin >> A >> B;
	int temp = 0;
	int tax1, tax2;
	while (true) {
		tax1 = (int)temp * 0.08;
		tax2 = (int)temp * 0.1;
		if (tax1 == A && tax2 == B) {
			cout << temp << endl;
			break;
		}
		if (temp > 1000) {
			cout << "-1" << endl;
			break;
		}
		temp++;
	}
}