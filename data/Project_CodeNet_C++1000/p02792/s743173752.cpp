#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#include <istream>

using namespace std;

typedef long long ll;
typedef pair<ll, int> P;



int main(){
	ll n;
	int d[10][10];
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			d[i][j] = 0;
		}
	}

	cin >> n;
	for(int i=1;i<=n;i++){
		string s = to_string(i);
		int top = s[0]-'0';
		int end = i%10;
		d[top][end]++;
	}

	ll ans = 0;
	for(int i=1;i<10;i++){
		for(int j=1;j<10;j++){
			ans += d[i][j]*d[j][i];
		}
	}

	cout << ans << endl;

	return 0;
}