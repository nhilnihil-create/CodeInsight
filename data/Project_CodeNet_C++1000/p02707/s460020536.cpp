#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll

const ll mod = 1e9 + 7;

main(){
	int n;
	cin >> n;
	int a[n];
	
	for(int i=0;i<n;i++){
		a[i] = 0;
	} 
	for(int i=0;i<n-1;i++){
		int t;
		cin >> t;
		t--;
		a[t]++;
	} 

	for(int i=0;i<n;i++){
		cout << a[i] << endl;
	}

	return 0;
}
