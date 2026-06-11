#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N, X;
	cin >> N >> X;

	vector<int> D;
	D.push_back(0);
	for (int i = 1; i < N + 1; i++) {
		int l;
		cin >> l;
		int d = D[i - 1] + l;
		D.push_back(d);
	}

	int count = 0;
	for (int i = 0; i<N + 1; i++) {
		if (D[i] <= X) {
			count++;
		}
	}

	cout << count << endl;


}


