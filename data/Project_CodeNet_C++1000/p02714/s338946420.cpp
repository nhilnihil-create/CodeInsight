
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;


int main(int argc, char* argv[]) {
	int n;
	string s;
	cin >> n >> s;

	set<int> r;
	set<int> g;
	set<int> b;

	for (int i = 0; i < n; i++) {
		switch (s[i])
		{
		case 'R':
			r.insert(i);
			break;
		case 'G':
			g.insert(i);
			break;
		case 'B':
			b.insert(i);
			break;

		default:
			break;
		}
	}

	ll cnt = 0;

	if (b.size() == 0) {
		cout << 0 << endl;
		return 0;
	}

	

	for (int ri : r) {
		for (int gi : g) {

			int c = b.size();
			int i = min(ri, gi);
			int j = max(ri, gi);
			
			
			if (b.find(2 * j -i) != b.end()) {
				c--;
			}

			if (b.find(2 * i - j) != b.end()) {
				c--;
			}

			if ((i + j) % 2 == 0 && b.find((i + j) / 2) != b.end()) {
				c--;
			}

			cnt += c;
			
		}
	}

	cout << cnt << endl;


}