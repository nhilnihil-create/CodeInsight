#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int main() {
	
	while(true){
		int m, nmin, nmax;
		cin >> m >> nmin >> nmax;
		
		if(m == 0){
			break;
		}
		
		int a[1000];
		
		for(int i = 0; i < m; i++){
			cin >> a[i];
		}
		
		int mm = 0;
		int ans = 0;
		
		for(int i = nmin; i <= nmax; i++){
			if(a[i - 1] - a[i] >= mm){
				mm = a[i - 1] - a[i];
				ans = i;
			}
		}
		
		cout << ans << endl;
		
	}
	return 0;
}


