#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdint.h>
#include<vector>
#include<deque>
#include<stack>
#include<string>
#include<cstring>
#include<time.h>
#include<array>
#include<iomanip>
#include<list>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<random>
#include<bitset>
#include <queue>
#include <map>


using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ldouble = long double;


//BDD,ZDD,kdtree, bdtree,bicalc, bolonoy, doloney,chinesemod,segmenttree,daikusutora, saidairyuu, 2bugurahu, heirokenshutu, topologicalsort, kyourenketuseibun


#define PRI(s) cout << s << endl
#define PRIY PRI("Yes")
#define PRIN PRI("No")

int main() {
	string s;
	char m[2];
	int c[2] = { 1,0 };
	cin >> s;
	m[0] = s[0];
	bool full = false;
	for (int i = 1; i < 4; ++i) {
		if(full){
			if (s[i] == m[0])c[0]++;
			else if (s[i] == m[1]) c[1]++;
			else {
				PRIN;
				return 0;
			}
		}
		else {
			if (s[i] == m[0])c[0]++;
			else {
				m[1] = s[i];
				c[1]++;
				full = true;
			}
		}
	}
	if (c[0] == 2 && c[1] == 2)PRIY;
	else PRIN;
	return 0;
}