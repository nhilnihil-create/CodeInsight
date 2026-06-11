#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <cmath>
#include <iomanip>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define MCLR(a) memset((a), -1 ,sizeof(a))
#define SZ(a) (sizeof(a))
#define FILL(a,v) fill((int*)a,(int*)(a+(SZ(a)/SZ(*(a)))),v)
bool cheak(int x, int y, int xMax, int yMax){return x >= 0 && y >= 0 && xMax > x && yMax > y;}
const int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
typedef pair<int, int> P;
typedef long long ll;
typedef unsigned long long ull;
const int mod = 10007;
const int INF = 2147483647;

int main()
{
	string s;

	while (getline(cin, s) && !(s[0] == '.' && s.size()==1)){
		int i;
		stack<char> sc;
		for(i = 0;i < s.size();i++){
			if (s[i] == '(' || s[i] == '[')sc.push(s[i]);

			if (s[i] == ')')if (sc.size() && sc.top() == '('){
				sc.pop();
			}
			else break;
			if (s[i] == ']')if (sc.size() && sc.top() == '['){
				sc.pop();
			}
			else break;
		}
		if (i == s.size() && !sc.size())cout << "yes" << endl;
		else							cout << "no"	<< endl;
	}

}