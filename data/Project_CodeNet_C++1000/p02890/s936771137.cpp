#include <bits/stdc++.h>
using namespace std;

/*		
for k == 1, just number of cards
for k == 2, we choose one from current maximum and one from next maximum?

if the maxcnt > n/k, then we will have dup
else we maintain the invariant that maxcnt <= n/k, easy

the question now is how to keep this maxcnt
all # > n/k just don't exist?
if we sort cnt's
keep pointer such that all on this and to the left
*/

int main(){
	int n;	
	scanf("%d", &n);
	int a[n + 1] = {};
	for(int i = 0;i < n; ++i){
		int x;
		scanf("%d",&x);
		++a[x];
	}
	vector<int> v;
	for(int i = 1;i <= n; ++i){
		if(a[i] != 0){
			v.push_back(a[i]);
		}
	}
	sort(v.begin(), v.end());
	int sz = v.size();
	int sum = n;
	for(int i = 1;i <= n; ++i){
		while(v.back() > sum/i){
			int ptr = v.size();
			int sub = 0;
			while(ptr && v[ptr-1] > sum/i){
				--v[--ptr];
				++sub;
			}
			sum-=sub;
		}
		cout << sum/i << '\n';
	}
}
