#include <iostream>
using namespace std;
int bfs(int, int, int);
int a[10];
int main(void){

	int n;

	cin >> n;
	for (int n_count = 0; n_count < n; n_count++){

		for (int i = 0; i < 10; i++){

			cin >> a[i];
		}

		if (bfs(0, 0, 0) == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}

int bfs(int i, int l, int r){

	int ans = 0;

	if (i == 10)
		ans = 1;

	if (l < a[i])
		ans = bfs(i + 1, a[i], r);

	if (r < a[i])
		ans = bfs(i + 1, l, a[i]);

	return ans;
}