#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <time.h>
using namespace std;
typedef long long ll;

struct Edge {
	int from;
	int to;
};

bool cmprFrom(Edge e1, Edge e2)
{
	if (e1.from < e2.from) {
		return true;
	}
	return false;
}

int  main()
{
	int N; cin >> N;
	vector<int> X(N), L(N);
	vector<Edge> E(N);
	for (int i = 0; i < N; ++i) {
		cin >> X[i] >> L[i];
		E[i].from = X[i] - L[i];
		E[i].to = X[i] + L[i];
	}
	sort(E.begin(), E.end(), cmprFrom);
	auto it = E.begin();
	auto nt = it; ++nt;
	while(nt != E.end()){
		if (it->to > nt->from) {
			if (it->to > nt->to) {
				it = E.erase(it);
				nt = it; ++nt;
			}
			else {
				nt = E.erase(nt);
			}
		}
		else {
			it = nt;
			++nt;
		}
	}
	cout << E.size() << endl;;
}
