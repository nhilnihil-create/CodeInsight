#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define length(array) (sizeof(array) / sizeof(*array))
#define p_var(var) (cout << #var << " = " << var << endl)


int main() {
	cin.tie(false);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		string input;
		cin >> input;
		set<string> pattern;
		string front, rear;
		
		pattern.clear();
		front = rear = "";
		
		for(int j=1; j<=input.size()-1; j++) {
			front = input.substr(0, j);
			rear = input.substr(j);
			
			for(int k=0; k<4; k++) {
				pattern.insert(front+rear);
				pattern.insert(rear+front);

				if(k % 2 == 0)
					reverse(front.begin(), front.end());
				else
					reverse(rear.begin(), rear.end());
			}
		}
		cout << pattern.size() << endl;
	}

	return EXIT_SUCCESS;
}