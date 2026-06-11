#include <iostream>
#include<iomanip>
#include <string>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
#include<math.h>
#include<stack>
#include<set>
#include<map>
#define INF long long int(1e18+1)
#define rep(i,n,m) for(int i=n;i<m;i++)

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int>Prime(100101, 0);
	Prime[1] = true;
	rep(i, 2, 1000101) {
		long int x = i;
		while (x < 100101) {
			Prime[x]++;
			x += i;
		}
	}
	rep(i, n, 100101) {
		if (Prime[i]==1) {
			cout << i << endl;
			break;
		}
	}
}