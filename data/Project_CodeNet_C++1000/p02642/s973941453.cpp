#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

using ll = long long;

using namespace std;

const ll mod = 1e9 + 7;

int main(){	
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> table(12345678 , 0);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		table[a[i]]++;
	}
	
	sort(a.begin() , a.end());
	
	ll cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 2; a[i] * j <= a[n - 1]; j++){
			table[a[i] * j]++;
		}
	}
	
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(table[a[i]] <= 1)ans++;
	}
	cout << ans << endl;
	return 0;
}
 
