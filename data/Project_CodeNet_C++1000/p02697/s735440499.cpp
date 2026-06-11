#include <iostream>
using namespace std;

int N, M; bool flag = false;

int main() {
	cin >> N >> M;
	int cnt = M + 1;
	for (int i = M; i >= 1; i--) {
		if (N % 2 == 0 && (cnt - i) * 2 >= N && flag == false) { cnt++; flag = true; }
		cout << i << " " << cnt << endl;
		cnt++;
	}
	return 0;
}