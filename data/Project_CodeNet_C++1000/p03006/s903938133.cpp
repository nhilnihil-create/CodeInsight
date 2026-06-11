#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
	int N = 0;

	cin >> N;

	vector<pair<int, int>> position;

	for (int i = 0; i < N; ++i) {
		pair<int, int> curPos;
		cin >> curPos.first >> curPos.second;
		position.push_back(curPos);
	}

	map<pair<int, int>, int> dist;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (i != j) {
				pair<int, int>curDist = make_pair(position[i].first - position[j].first, position[i].second - position[j].second);
				if (dist.count(curDist) == 0) {
					dist[curDist] = 1;
				}
				else {
					++dist[curDist];
				}
			}
		}
	}

	int maxDistCount = 0;
	for(const auto& curDist: dist){
		int curCount = curDist.second;
		if (curCount > maxDistCount) {
			maxDistCount = curCount;
		}
	}

	cout << N - maxDistCount << endl;

	return 0;
}