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
	int r, g, b, k,h=0;
	cin >> r >> g >> b >> k;
	if (g > r && b > g) {
		cout << "Yes" << endl;
		return 0;
	}
	
	while (k>=h) {
		

		if (g > r) {
			if (b > g) {
				cout << "Yes" << endl;
				return 0;
			}
			break;
		}
		g = g * 2;
		h++;
	
	}
	while (k >= h) {
		
	
		if (g > r && b > g) {
			cout << "Yes" << endl;
			return 0;
		}
		b = b * 2;
		h++;
	}
	cout << "No" << endl;
	
	return 0;
}



