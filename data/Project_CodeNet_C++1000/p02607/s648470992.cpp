#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int count = 0;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;

		if ((i + 1) % 2 == 1) {
			//マス番号が奇数
			if (a % 2 == 1) {
				//マスに書かれた整数が奇数
				count++;
			}
		}
	}
	cout << count << endl;
}
