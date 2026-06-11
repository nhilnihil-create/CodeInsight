#include<iostream>
#include<vector>
#include<string>
#include<bitset>
#include<algorithm>
#include<map>
#include<queue>
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> s(n,1);
	int x;
	for (int i = 2; i <= n; i++) {
		//cout << i << endl;
		x = -1;
		while (1) {
			x += i;
			if (x >= n)
				break;
			s[x]++;
		}
	}

	long long sum = 0;
	for(int i=1;i<=n;i++){
		sum +=(long long) i * s[i - 1];
	}


	/*rep(i, n)
		cout << s[i] << endl;*/
	cout << sum << endl;
	return 0;
}