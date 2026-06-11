// #define _GLIBCXX_DEBUG // for STL debug (optional)

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
using namespace std;
void dump_func() { cerr << endl; }
template <class Head, class... Tail>
void dump_func(Head &&h, Tail &&... t) { cerr << h << (sizeof...(Tail) == 0 ? "" : ", "), dump_func(forward<Tail>(t)...); }
#define dump(...) cerr << "/* " << #__VA_ARGS__ << " :[" << __LINE__ << ":" << __FUNCTION__ << "]" << endl, dump_func(__VA_ARGS__), cerr << "*/\n\n";
typedef long long ll;

int main()
{
	string s;
	cin >> s;
	if (s[s.size() - 1] == 's')
	{
		cout << s << "es" << endl;
	}
	else
	{
		cout << s << "s" << endl;
	}
}
