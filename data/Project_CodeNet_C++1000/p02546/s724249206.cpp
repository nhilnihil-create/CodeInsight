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
	string a;
	cin >> a;
	if (a[a.size() - 1] == 's') {
		cout << a + "es";
	}
	else
		cout << a + "s";
}

