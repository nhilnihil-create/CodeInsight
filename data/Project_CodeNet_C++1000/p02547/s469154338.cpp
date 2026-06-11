#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iterator>
#include <deque>
#include <bitset>
#include <list>
#include <queue>
#include <set>
#include <stack>
#include <functional>
#include <iterator>
#include <locale>
#include <memory>
#include <stdexcept>
#include <utility>
#include <fstream>
#include <ios>
#include <iosfwd>
#include <iomanip>
#include <istream>
#include <sstream>
#include <streambuf>
#include <complex>
#include <numeric>
#include <valarray>
#include <exception>
#include <limits>
#include <new>
#include <typeinfo>
#include <bitset>
#include <queue>

using namespace std;

int main() {
	int a, b, s, c=0;
	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> b >> s;
		if (b == s) {
			c++;
		}
		else
			c = 0;
		if (c >= 3) {
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
}

