#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<string> s(n);
	rep(i, n) cin >> s[i] >> a[i];
	string x;
	cin >> x;
	int ans = 0;
	bool flag = false;
  int k;
	rep(i, n) {
		if (s[i] == x){
          flag = true;
          k=i;
        }
		if (flag) ans += a[i];
	}
  ans-=a[k];
	cout << ans << endl;
}