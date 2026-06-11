#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int main() {
    int h, w, n;
	cin >> h >> w >> n;
	int ans;
	int a = max(h, w);
	ans = (n + a - 1) / a;
	cout << ans << endl;
}