#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <string>
#include <tuple>
#include <functional>
#include <numeric>
#include <cmath>
#include <iomanip>
#include <map>
#include <random>
//#include "toollib.h"
//#include "puzzle.h"
#define INT_MAX 2147483647
#define Loop(i, n) for(int i = 0; i < (int)n; i++)
#pragma warning (disable:4018)
#pragma warning (disable:4244)

using namespace std;
typedef long long int lint;


//***** Main Program *****

int cnt = 0;

void insertion(vector<int>* A, int g) {
	for (int i = g; i < (*A).size(); i++) {
		int v = (*A)[i];
		int j = i - g;
		while (j >= 0 && (*A)[j]>v) {
			(*A)[j + g] = (*A)[j];
			j = j - g;
			cnt++;
		}
		(*A)[j + g] = v;
	}
}

int main(){
	int N;
	cin >> N;
	vector<int> A(N);
	Loop(i, N) cin >> A[i];
	deque<int> g{ 1 };
	while (g.front() * 3 + 1 < N) g.push_front(g.front() * 3 + 1);
	cout << g.size() << endl;
	cout << g[0];
	for (int i = 1; i < g.size(); i++) cout << " " << g[i];
	cout << endl;
	Loop(i, g.size()) {
		insertion(&A, g[i]);
	}
	cout << cnt << endl;
	Loop(i, A.size()) cout << A[i] << endl;
	return 0;
}