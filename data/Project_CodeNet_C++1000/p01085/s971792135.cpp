#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	vector<int> result(0);
	int m;
	int nMin;
	int nMax;
	cin >> m;
	cin >> nMin;
	cin >> nMax;
	while (m != 0 || nMin != 0 || nMax != 0) {
		vector<int> array(0);
		for (int i = 0; i < m; i++) {
			int p;
			cin >> p;
			array.push_back(p);
		}
		int tmp = -1;
		int diffMax = -10000;
		for (int i = nMin - 1; i < nMax; i++) {
			int diff = array[i] - array[i + 1];
			if (diff >= diffMax) {
				diffMax = diff;
				tmp = i + 1;
			}
		}
		result.push_back(tmp);
		cin >> m;
		cin >> nMin;
		cin >> nMax;
	}
	
	for (int &num:result) {
		cout << num << endl;
	}
	
	return 0;
}

