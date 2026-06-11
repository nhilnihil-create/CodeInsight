#include <map>
#include <cstdio>
using namespace std;
int main(){
	int n;
	scanf("%d", &n);
	int x[n], y[n], ans = 0;
	for (int i = 0; i < n; i++) scanf("%d %d", &x[i], &y[i]);
	map<pair<int, int>, int> m;
	for (int i = 0; i < n - 1; i++){
		for (int j = i + 1; j < n; j++){
			pair<int, int> p = {x[i] - x[j], y[i] - y[j]};
			m[p]++;
			ans = max(ans, m[p]);
			p.first = -p.first;
			p.second = -p.second;
			m[p]++;
			ans = max(ans, m[p]);
		}
	}
	printf("%d\n", n - ans);
}