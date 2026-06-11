#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

int main(void) {
	int N,M;
	cin >> N;
	cin >> M;

	while (N!=0||M!=0) {
		std::vector< std::vector<int> > all(11);
		int money = M;
		int ex_all = 0;
		int cost;
		int d,e;

		for (int i = 0; i < N; i++) {
			cin >> d;
			cin >> e;
			std::vector<int>::iterator itr = all[e].begin();
			itr = all[e].insert(itr, d);
		}

		for (int i = 10; i > 0 && money > 0; i--) {
			for (std::vector<int>::iterator itr = all[i].begin(); itr != all[i].end(); ++itr) {
				if (*itr < money) {
					money -= *itr;
					*itr = 0;
				}
				else {
					*itr -= money;
					money = 0;
				}
			}

		}
		for (int i = 1; i < 11; i++) {
			for (std::vector<int>::iterator itr = all[i].begin(); itr != all[i].end(); ++itr) {
				ex_all += i * (*itr);
			}
		}
		cout << ex_all << endl;
		cin >> N;
		cin >> M;
	}
	return 0;
}