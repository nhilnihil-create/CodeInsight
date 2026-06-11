#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<vector<int>>tisei;
int tate, yoko;
void shima(int a, int b) {
	tisei[a][b] = 0;
	for (int c = a-1; c < a+2; c++) {
		for (int d = b - 1; d < b + 2; d++) {
			if (c > -1 && d > -1 && c< tate&d < yoko&&tisei[c][d])shima(c, d);
		}
	}
}
int main() {
	int a, b;
	while (cin >> a >> b, a | b) {
		tate = b;
		yoko = a;
		tisei.clear();
		for (int c = 0; c < b; c++) {
			vector<int>o(a);
			for (int e = 0; e < a; e++) {
				cin >> o[e];
			}
			tisei.push_back(o);
		}
		int s = 0;
		for (int g = 0; g < b; g++) {
			for (int h = 0; h < a; h++) {
				if (tisei[g][h]) { s++;  shima(g, h); }
			}
		}
		cout << s << endl;
	}
}