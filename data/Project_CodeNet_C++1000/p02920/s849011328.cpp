#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#include<functional>
using namespace std;

#define f(i,n) for(int i=0;i<(int)n;i++)

int main(void) {
	vector<int>b;
	vector<int>a;
	vector<bool>used;
	bool v = true;
	int n;
	int k = 1;
	int x, y, z;
	scanf("%d", &n);
	f(i, n)k = k * 2;
	f(i, k) {
		scanf("%d", &x);
		a.push_back(x);
		used.push_back(false);
	}
	sort(a.begin(), a.end(), greater<int>());
	b.push_back(a[0]);
	used[0] = true;
	y = 1;
	f(i, n) {
		z = 0;
		f(j, k) {
			if ((!used[j]) && (a[j] < b[z])) {
				used[j] = true;
				b.push_back(a[j]);
				z++;
				if (z >= y)break;
			}
		}
		if (z < y) {
			v = false;
			break;
		}
		y = y * 2;
		sort(b.begin(), b.end(), greater<int>());
	}
	if (v)printf("Yes\n");
	else printf("No\n");

	return 0;
}