#include <iostream>
using namespace std;

const int mxN = 1e5 + 5;
bool done[mxN];
int WA[mxN];

int main() {
	int n, m;
	cin >> n >> m;
	int ac = 0, wa = 0;
	for(int i = 1; i <= m; ++i) {
		int p;
		cin >> p;
		string s;
		cin >> s;
		if(done[p])
			continue;
		if(s == "AC") {
			wa += WA[p];
			++ac;
			done[p] = true;
		}
		else
			++WA[p];
	}
	cout << ac << ' ' << wa;
}
