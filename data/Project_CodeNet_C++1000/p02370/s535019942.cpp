#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <array>
#include <map>
using namespace std;

#define Getsign(n) ((n > 0) - (n < 0))

typedef vector<int> Ivec;
typedef pair<int, int> Pos;

int main() {
	vector<pair<int,vector<int>>> graph;
	int v, e;
	scanf("%d %d", &v, &e);

	for (int i = 0; v > i; i++) {
		graph.push_back({i,vector<int>()});
	}
	for (int i = 0; e > i; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		graph[b].second.push_back(a);
	}
	while (v) {
		for (int i = 0; v > i; i++) {
			if (!graph[i].second.size()) {
				printf("%d\n", graph[i].first);
				int num = graph[i].first;
				graph.erase(graph.begin()+i);
				v--;
				for (int j = 0; v > j; j++) {
					auto itr = find(graph[j].second.begin(), graph[j].second.end(), num);
					if(itr != graph[j].second.end())
						graph[j].second.erase(itr);
				}
			}
		}
	}


	return 0;
}