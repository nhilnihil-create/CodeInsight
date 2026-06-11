#include <bits/stdc++.h>
using namespace std;

const int N=18;
int a[(1<<N)+5];
int main() {
	int n;
	scanf("%d", &n);
	for(int i=0;i<(1<<n);i++) scanf("%d", &a[i]);
	sort(a,a+(1<<n));
	multiset<int> s;
	for(int i=0; i<(1<<n)-1; i++) s.insert(a[i]);
	vector<int> v;
	v.push_back(a[(1<<n)-1]);
	for(int i=0; i<n; i++) {
		auto temp=v;
		for(auto j:v) {
			// find element smaller than j
			auto it=s.lower_bound(j);
			if(it==s.begin()) {
				puts("No");
				return 0;
			}
			--it;
			temp.push_back(*it);
			s.erase(it);
		}
		sort(temp.begin(), temp.end());
		reverse(temp.begin(), temp.end());
		swap(temp,v);
	}
	puts("Yes");
	return 0;
}
