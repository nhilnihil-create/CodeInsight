#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	float N;
	cin >> N;

	float count = 0;
	for (int i = 1; i <= N; i++) {
		if (i % 2 == 1) {
			count++;
		}
	}

	cout << count / N << endl;

}



