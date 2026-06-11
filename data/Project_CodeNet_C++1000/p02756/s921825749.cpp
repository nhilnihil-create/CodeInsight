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
	string S, front, back; cin >> S;
	int Q; cin >> Q;
	int temp2;
	string c;
	string result;
	bool S_reverse = false;
	for (int i = 0; i < Q; i++) {
		int temp;
		cin >> temp;
		if (temp == 1) {
			S_reverse = !S_reverse;
		}
		else {
			cin >> temp2 >> c;
			
			if (!S_reverse&& temp2 == 1) {
				front.insert(0, c);
			}

			if (!S_reverse && temp2 == 2) {
				back.insert(back.length(),c);
			}

			if (S_reverse && temp2 == 1) {
				back.insert(back.length(), c);
			}

			if (S_reverse && temp2 == 2) {
				front.insert(0, c);
			}
		}
	}
	if (!S_reverse) {
		result = front + S + back;
	}
	else {
		reverse(front.begin(), front.end());
		reverse(S.begin(), S.end());
		reverse(back.begin(), back.end());
		result = back + S + front;
	}
	cout << result << endl;
}