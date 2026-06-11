#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	unsigned int a[105] = {0};
	int res = 0;
	for (int i = 1; i <= N; ++i){
		cin >> a[i];
		if (i%2 && a[i]%2)
			res++;
	}

	cout << res << endl;

	return 0;
}
