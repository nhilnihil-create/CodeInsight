#include<iostream> 
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)



int main() {
	int n;
	cin >> n; 
		rep(i, n+1) {
			if ((i * 108)/100  == n) {
				cout << i << endl;
				return 0;
			}
		}
		cout << ":(" << endl;
	
	return 0;
}