#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	long long N, A, B;
	cin >> N >> A >> B;
	long long remainder = min(N % (A + B), A);
	long long blue_ball = N / (A + B) * A + remainder;
	cout << blue_ball << endl;
}