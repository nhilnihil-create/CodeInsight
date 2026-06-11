#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <random>
using namespace std;
typedef long long ll;
const int INF = 987654321;
const int MAX_N = 3e5 + 2, MAX_X = 1e6 + 2;

int main()
{
	string s;
	cin >> s;
	if (s.back() == 's')cout << s << "es";
	else cout << s << "s";
}