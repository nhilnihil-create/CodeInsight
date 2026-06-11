#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "iomanip"
#include "random"

using namespace std;

const long long int MOD = 1000000007;
const long double EPS = 0.00000001;
const long double PI = 3.1415926535897932384626433;

long long int N, M, K, H, W;
long double L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	getline(cin, s);
	while (s != ".") {
		stack <char>st;
		bool flag = true;
		for (auto i : s) {
			if (i == '(' || i == '[') {
				st.push(i);
			}
			if (i == ')') {
				if (st.empty()) {
					flag = false;
					break;
				}
				if (st.top() == '[') {
					flag = false;
					break;
				}
				st.pop();
			}
			if (i == ']') {
				if (st.empty()) {
					flag = false;
					break;
				}
				if (st.top() == '(') {
					flag = false;
					break;
				}
				st.pop();
			}
		}
		if (flag&&st.empty()) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
		getline(cin, s);
	}
	return 0;
}