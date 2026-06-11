#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
typedef unsigned int ui;
int main(){
	int n; string s;
	while (cin >> n) {
		if (n == 0)break;
		int bef = 0;
		int lnow = 0; int rnow = 0;
		int count = 0;
		for (int i = 0; i < n; i++) {
			cin >> s;
			if (s == "lu")lnow = 1;
			else if (s == "ru")rnow = 1;
			else if (s == "ld")lnow = 0;
			else rnow = 0;
		    if ((bef == 0 && rnow + lnow == 2) || (bef == 1 && rnow + lnow == 0)) {
			    count++; bef = (bef + 1) % 2;
		    }
		}
		cout << count << endl;
	}
	return 0;
}
