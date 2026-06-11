#include<iostream>
#include<cstdio>
#include<list>
#include<vector>
using namespace std;

int main() {
	int a, b;
	while (cin >> a >> b, a | b) {
		list<int>L;
		for (int c = 0; c < a; c++)L.push_back(a-c);
		for (int d = 0; d < b; d++) {
			int e, f, i = 1;
			scanf("%d%d", &e, &f);
			vector<int>V;
			for (auto g = L.begin(); g != L.end(); g++,i++) {
				if (i >= e&&e + f > i) {
					V.push_back(*g);
					L.erase(g);
					g--;
				}
			}
			for (int r = 0; r < V.size(); r++)L.push_front(V[V.size() - r - 1]);
		}
		cout << L.front() << endl;
	}
}