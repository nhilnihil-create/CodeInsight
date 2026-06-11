#include "iostream"
#include "vector"

using namespace std;

int main()
{
	int x = 0, y = 0;
	vector<vector<int>> hw;
	do {
		cin >> x >> y;
		hw.push_back(vector<int>{x, y});
	} while (x != 0 && y != 0);

	for (int i = 0; i < hw.size();++i) {
		for (int h = 0; h < hw[i][0]; ++h) {
			for (int w = 0; w < hw[i][1]; ++w) {
				cout << "#";
			}
			cout << endl;
		}
		if(hw[i][0] != 0 && hw[i][1] != 0) cout << endl;
	}

    return 0;
}