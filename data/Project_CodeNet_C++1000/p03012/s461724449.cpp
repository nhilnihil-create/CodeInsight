#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> W;
	int total_w = 0;
	for (int i = 0; i < N; i++) {
		int w;
		cin >> w;
		W.push_back(w);
		total_w += w;
	}

	int s1 = 0;
	int min_abs = total_w;
	for (int i = 0; i < N - 1; i++) {
		s1 += W[i];
		int s2 = total_w - s1;
		min_abs = min(min_abs, abs(s1 - s2));
	}

	cout << min_abs << endl;
}




