#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> store;
	for(int i=0;i<n;++i)cin >> v[i];
	int last = *max_element(v.begin(), v.end());
	for(int i=1;i<=last;++i){
		int ans = 0;
		for(int j = 0;j<n;++j){
			ans += pow(v[j] - i, 2);	
		}	
		store.push_back(ans);
	}
	cout << *min_element(store.begin(), store.end());
}
