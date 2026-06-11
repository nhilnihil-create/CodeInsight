#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <string.h>
#include <cassert>

#ifdef _DEBUG
#define typeof(X) std::identity<decltype(X)>::type //C++0x (for vs2010)
#else
#define typeof(X) __typeof__(X) // for gcc
#endif

#define sz(a)  int((a).size())
#define FOREACH(it, c) for (typeof((c).begin()) it=(c).begin(); it != (c).end(); ++it)
#define FOR(i,count) for (int i = 0; i < (count); i++)
#define V_CIN(v) do{for(int i = 0; i < sz(v); i++) cin >> (v)[i];}while(0)
#define all(c) (c).begin(),(c).end()

using namespace std;
static const double EPS = 1e-5;
typedef long long ll;
const int MODULO = 1000000007;

typedef pair<int,int> Pii;

bool t[123456*2+10];

int main()
{
	memset(t,1,sizeof(t));
	t[1] = false; 
	int mx = (int)sqrt(123456.0 * 2) + 1;
	for(int i = 2; i < mx; i++){
		if(t[i]){
			for(int j = i*2; j < sizeof(t); j += i){
				t[j] = false;
			}
		}
	}

	int a;
	while(cin >> a,a){
		int count = 0;
		for(int i = a + 1; i <= a * 2; i++) 
			count += t[i];
		cout << count << endl;
	}

	return 0;
}