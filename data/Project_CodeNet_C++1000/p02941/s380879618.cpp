#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<int> A,B;


int main()
{
	long long ans = 0;
	cin >> N;
	A = vector<int>(N + 1, 0);
	B = vector<int>(N + 1, 0);

	auto c = [](int l, int r) { 
		return B.at(l) - A.at(l) < B.at(r) - A.at(r); 
	};
	priority_queue<int, vector<int>, decltype(c)> q(c);

	for (int i = 1; i < N + 1; i++) {
		cin >> A.at(i);
	}
	for (int i = 1; i < N + 1; i++) {
		cin >> B.at(i);
		q.push(i);
	}


	while (!q.empty()) {
		int tgt = q.top();
		q.pop();
		int n1 = (tgt + N - 2) % N + 1;
		int n2 = tgt % N + 1;

		int minus = B.at(n1) + B.at(n2);

		int div = (B.at(tgt) - A.at(tgt)) / minus;

		if (div > 0) {
			B.at(tgt) -= minus * div;
			ans += div;

			if (B.at(tgt) != A.at(tgt)) {
				q.push(tgt);
			}
		}
		else {
			break;
		}
	}


	bool suc = true;
	for (int i = 1; i < N + 1 && suc; i++) {
		suc = A.at(i) == B.at(i);
	}

	if (suc) {
		cout << ans << endl;
	}
	else {
		cout << -1 << endl;
	}


	return 0;
}