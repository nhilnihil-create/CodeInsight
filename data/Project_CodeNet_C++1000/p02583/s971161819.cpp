#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	int count = 0;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		}		
		
	std::sort(a.begin(), a.end());
	
	for(int i = 0; i < n; ++i){
		for(int j = i + 1; j < n; ++j){
			for(int k = j + 1; k < n; ++k){
				if(a[i] != a[j] && a[j] != a[k] && a[i] + a[j] > a[k]){
					count++;
					}
				}
			}
		}
	
	cout << count << endl;
	return 0;
}