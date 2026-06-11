#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <set>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
#include <cstdlib>
#include <iomanip>
#include <ctime>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define ff first
#define ss second

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
  	cin >> s;
  	if (s[s.size() - 1] == 's')
    	s += "es";
  	else
    	s += "s";
  	cout << s;
    return 0;
}