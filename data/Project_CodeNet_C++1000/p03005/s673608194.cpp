#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(int argc, char const *argv[])
{
	int n, k; cin >> n >> k;
	if (k == 1) {
		printf("0\n");
		return 0;
	}
	int r = n - k; 
	cout << r << endl;
	return 0;
}
