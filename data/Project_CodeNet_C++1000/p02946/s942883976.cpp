#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <numeric>
#include <iterator>

using namespace std;

namespace {

}

int main()
{
	long long K, X;
	long long max(2000001);

	cin >> K >> X;

	for (long long i = X - (K - 1); i <= X + (K - 1); ++i){
		cout << i << ' ';
	}
	cout << endl;

	return 0;
}