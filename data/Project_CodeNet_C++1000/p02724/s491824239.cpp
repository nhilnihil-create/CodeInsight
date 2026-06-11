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
#define speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

int main() {
	long long a, b, c, happy=0;
	cin >> a;
	b = a / 500;
	happy = b * 1000;
	c = (a % 500) / 5;
	happy += c * 5;
	cout << happy;
}

