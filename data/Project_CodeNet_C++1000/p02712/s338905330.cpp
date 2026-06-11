#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	long long N;
	cin >> N;

	long long sum = 0;
	for (int i = 1; i <= N; i++) {
		if (i % 3 == 0 && i % 5 == 0) {
			//cout << "FizzBuzz" << endl;
		}
		else if (i % 3 == 0) {
			//cout << "Fizz" << endl;
		}
		else if (i % 5 == 0) {
			//cout << "Buzz" << endl;
		}
		else {
			sum += i;
		}
	}

	cout << sum << endl;
}




