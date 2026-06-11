#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt"
int main() {
	while (1) {
		int N; cin >> N;
		if (!N)break;
		int a = 0;
		for (int from = 1; from < N; ++from) {
			
			for (int num = 2; num <= N; ++num) {
				int ans = (from + (from + num - 1))*num / 2;
				if (ans == N)a++;
			}
		}
		cout << a << endl;
	}
	return 0;
}