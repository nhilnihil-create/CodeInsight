#include <iostream>
#include <cmath>

using namespace std;

void solve() {
    int n; cin >> n;
	int cur{0}, res{0};
	while (cur < n) {
	    cur++;
	    if (cur == 10 || cur == 1000 || cur == 100000) {
	        cur *= 10;
	        if (cur <= n) {
	            res++;
	        }
	        continue;
	    }
	    res++;
	}
	
	cout << res << endl;    
}

int main() {
	solve();
}
