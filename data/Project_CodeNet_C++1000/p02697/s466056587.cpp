#include <iostream>
#include <cstdio>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
int n,m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1,j = m;i < j;i++,j--){
		cout << i << " " << j << endl;
	}
	for(int i = m + 1,j = 2 * m + 1;i < j;i++,j--){
		cout << i << " " << j << endl;
	}
	return 0;
}