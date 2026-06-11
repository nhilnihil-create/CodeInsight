#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
typedef long long ll;
int K;
int F[32] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> K;
	cout << F[K-1] << nl;
	return 0;
}