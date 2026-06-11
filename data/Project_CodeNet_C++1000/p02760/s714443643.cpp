#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <numeric>
#include <iterator>
using namespace std;

namespace {

}

int main()
{
	//vector<int> a(3);
	vector<vector<int>> a(3);

	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 3; ++j){
			int tmp;
			cin >> tmp;
			a[i].push_back(tmp);
			// cin >> a[i][j];
		}
	}

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i){
		int tmp;
		cin >> tmp;
		for (int i = 0; i < 3; ++i){
			for (int j = 0; j < 3; ++j){
				if (a[i][j] == tmp){
					a[i][j] = 0;
					goto out1;
				}
			}
		}
	out1:;
	}

	// 判定
	for (int i = 0; i < 3; i++){
		if ((a[i][0] == 0 && a[i][1] == 0 && a[i][2] == 0)
			|| (a[0][i] == 0 && a[1][i] == 0 && a[2][i] == 0))
		{
			cout << "Yes" << endl;
			return 0;
		}

	}

	if ((a[0][0] == 0 && a[1][1] == 0 && a[2][2] == 0)
		|| (a[2][0] == 0 && a[1][1] == 0 && a[0][2] == 0))
	{
		cout << "Yes" << endl;
		return 0;
	}

	cout << "No" << endl;


	return 0;
}
