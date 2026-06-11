#include <iostream>
#include<string>
#include<cmath>
#include<ciso646>
#include<cstring>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
#include<math.h>

//解説ac

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
long long momm(long long  a) {
	return a * (a - 1) / 2;
}
int main()
{//ゼロツーかわいい！！！！
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	rep(i, n) a[i]--;
	vector<int> cnt(n);
	rep(i, n) cnt[a[i]]++;
	long long tot = 0;
	rep(i, n)  //消去前のansを作り適宜消去していく
		tot += momm(cnt[i]);
	rep(i, n) {
		long long  ans = tot;
		ans -= momm(cnt[a[i]]); //まるごと消去した
		cnt[a[i]]--;
		ans += momm(cnt[a[i]]); //復元すべきところを復元した
		cout << ans << endl;
		cnt[a[i]]++;
	}
}

