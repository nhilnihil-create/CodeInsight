#include <string>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <iostream>
#include <functional>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <cmath>
#include <limits>
#include <tuple>
#include <queue>
#include <stack>

using namespace std;
typedef long long ll;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()

int main()
{
	string S;
	int Q;
	cin >> S >> Q;
	deque<char> dq(all(S));
	bool dir = true;
	rep(i, Q) {
		int T;
		cin >> T;
		if (T == 1) {
			dir = !dir;
		}
		else {
			int F;
			char C;
			cin >> F >> C;
			if (F == 1 && !dir || F == 2 && dir) {
				dq.push_back(C);
			} 
			else {
				dq.push_front(C);
			}
		}
	}
	if (!dir) {
		reverse(all(dq));
	}
	for (auto c : dq) {
		cout << c;
	}
	cout << endl;
	return 0;
}
