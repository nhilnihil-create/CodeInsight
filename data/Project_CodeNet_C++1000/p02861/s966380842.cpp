#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int INF=1e10;

int xy[10][2];

double dist(int i, int j) {
    double dx = xy[i][0] - xy[j][0];
    double dy = xy[i][1] - xy[j][1];
    return pow(dx * dx + dy * dy, 0.5);
}

int main() {
	int n;
	double ans = 0;
	cin >> n;
	vector<int> a(n);
	for(int i = 1;i<=n;i++){
		cin >> xy[i][0] >> xy[i][1];
	}
  for(int i = 0; i < n; i++) a[i] = i + 1;
	do {
     for(int i = 0; i < n - 1; i++) ans += dist(a[i], a[i+1]);
  } while(next_permutation(a.begin(), a.end()));
	int Factorial = 1;
  for(int i = 2; i <= n; i++) Factorial *= i;
  cout << fixed << setprecision(10) << ans / Factorial << endl;
}