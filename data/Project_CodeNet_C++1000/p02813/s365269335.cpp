#include <bits/stdc++.h>

using namespace std;

int main(){
#ifdef LOCAL
	freopen("input", "r", stdin);
#endif

	int n;
	vector<int> a, b, order;

	scanf("%d", &n);

	for (int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		a.push_back(x);
	}

	for (int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		b.push_back(x);
	}

	for (int i = 0; i < n; i++){
		order.push_back(i+1);
	}

	int ind = 1, orda = -1, ordb = -1;

	do {
		if (orda == -1){
			for (int i = 0; i < n; i++){
				if (order[i] != a[i])
					break;
				else if (i == n-1)
					orda = ind;
			}
		}
		if (ordb == -1){
			for (int i = 0; i < n; i++){
				if (order[i] != b[i])
					break;
				else if (i == n-1)
					ordb = ind;
			}
		}
		ind++;
	} while (next_permutation(order.begin(), order.end()));
	
	printf("%d\n", abs(orda - ordb));

	return 0;
}