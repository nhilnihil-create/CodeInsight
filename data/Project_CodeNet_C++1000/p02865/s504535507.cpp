#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<list>
#include<bitset>
#include<sstream>
using namespace std;

int main() {

	int N;
	cin >> N;

	cout << N / 2 + N % 2 - 1 << endl;

	return 0;
}