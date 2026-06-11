//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x6fffffff
#define INFL 0x6fffffffffffffffLL

int		n,m,k;
vector<int>	a(200001);

// 二分探索法
// k回まで切って丸太がindex以下になるればtrue;
bool isOK(int index) {
	int		i,c=0;
	
	for(i=0;i<n;i++) {
		c += (a[i]+index-1)/index - 1;
	}
	if (c<=k) return true;
	else return false;
}
// 汎用的な二分探索のテンプレ
int binary_search() {
    int left = 0; //「index = 0」が条件を満たすこともあるので、初期値は -1
    int right = m+1; // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* どんな二分探索でもここの書き方を変えずにできる！ */
    while (right - left > 1) {
        int mid = left + (right - left) / 2;

        if (isOK(mid)) right = mid;
        else left = mid;
    }

    /* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている */
    return right;
}

int main() {
	int		b,c,h,i,j,l,x,y;
	int		ans = 0;
	cin >> n >> k;
	for(i=0;i<n;i++) {
		cin >> a[i];
		m = max(m , a[i]);
	}

	if (m!=0) ans = binary_search();

	cout << ans << endl;
	return 0;
}
