#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int N;

int main()
{
	scanf ("%d", &N);
	vector<int> r; int mx = -1;
	for (int i = 0; i < (1 << N); i++){
		int x; scanf ("%d", &x);
		if (mx < x){
			if (mx != -1) r.push_back(mx);
			mx = x;
		}
		else r.push_back(x);
	}

	vector<int> h = { mx };
	sort(r.rbegin(), r.rend());
	while (!r.empty()){
		vector<int> p, q;
		sort(h.rbegin(), h.rend());

		int i = 0, j = 0;
		while (i <= h.size() && j < r.size()){
			if (i < h.size() && h[i] > r[j]){
				p.push_back(r[j]);
				i++; j++;
			}
			else{
				q.push_back(r[j]);
				j++;
			}
		}

		if (h.size() != p.size()){
			puts("No");
			return 0;
		}

		h.insert(h.end(), p.begin(), p.end());
		r = move(q);
	}
	puts("Yes");
	return 0;
}