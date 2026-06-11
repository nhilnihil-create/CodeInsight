#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){

	int h, w;
	while (cin >> h >> w) {
		if (h == 0 && w == 0) {
			break;
		}
		string top_bottom;
		top_bottom.resize(w, '#');
		string left_right;
		left_right.resize(w);
		left_right[0] = '#';
		*(left_right.end() - 1) = '#';
		fill(left_right.begin() + 1, left_right.end() - 1, '.');

		cout << top_bottom << endl;
		for (int i = 1; i < h - 1; ++i) {
			cout << left_right << endl;
		}
		cout << top_bottom << endl << endl;
	}


	return 0;
}