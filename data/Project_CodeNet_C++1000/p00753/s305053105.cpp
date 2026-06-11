#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

#define P pair<int, int>
#define MAX 246912

int main()
{	
	int n;
	bool p[MAX];
	fill(begin(p), end(p), 1);
	p[0] = p[1] = 0;
	for (int i = 2; i < sqrt(MAX) + 1; i++) {
		if (p[i]) {
			for (int j = i * 2; j < MAX; j += i)
				p[j] = 0;
		}
	}
	while (cin >> n, n) {
		int cnt = 0;
		for (int i = n+1; i <= 2*n; i++) {
			if (p[i]) cnt++;
		}
		cout << cnt << endl;
	}

	return 0;
}