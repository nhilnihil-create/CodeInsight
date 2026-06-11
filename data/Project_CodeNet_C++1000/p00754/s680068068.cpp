#define _USE_MATH_DEFINES
#include <iostream>
#include <complex>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <queue>
#include <cmath>
#include <math.h>
#include <numeric>
#include <list>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <climits>
#include <set>
#include <memory.h>
#include <memory>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <map>
#include <cassert>
#include <time.h>
#include <ctime>

using namespace std;

typedef complex<double> xy_t;
typedef pair<xy_t, xy_t> line;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<int , P> PP;
typedef pair<int, string> Ps;
typedef vector<int> vec;
typedef vector<vec> mat;
const int INF = 1 << 27;
const double EPS = 1e-9;
const double PI = 3.1415926535897932384626433832795;
const int CLK = CLOCKS_PER_SEC;

#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, m, n) for(int i = m; i < n; i++)

int main(){
	string s;
	while(getline(cin, s) && s != "."){
		stack<char> st;
		bool ok = true;
		for(int i = 0; i < (int)s.size(); i++){
			if(s[i] == '(') st.push(s[i]);
			if(s[i] == '[') st.push(s[i]);
			if(s[i] == ')'){
				if(st.empty() || st.top() != '('){
					ok = false;
				}else{
					st.pop();
				}
			}
			if(s[i] == ']'){
				if(st.empty() || st.top() != '['){
					ok = false;
				}else{
					st.pop();
				}
			}
		}
		if(ok && st.empty()) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}