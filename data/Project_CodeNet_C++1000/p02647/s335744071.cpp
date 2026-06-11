#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

#define ALL(v) begin(v),end(v)

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> as(n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &as[i]);
	}
	vector<int> acc;
	for(int i = 0; i < k && *min_element(ALL(as)) < n; ++i){
		acc.assign(n + 1, 0);
		for(int j = 0; j < n; ++j){
			++acc[max(j - as[j], 0)];
			--acc[min(j + as[j] + 1, n + 1)];
		}
		partial_sum(ALL(acc), acc.begin());
		acc.pop_back();
		as = acc;
	}
	for(int i = 0; i < n; ++i){
		printf("%d%c", as[i], i + 1 == n ? '\n' : ' ');
	}
}
