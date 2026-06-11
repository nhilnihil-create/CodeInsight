#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n; 
	cin >> n; 
	for(int i=1; i<=n; ++i)
		for(int j=i+1; j<=n; ++j){
			for(int o=0; (1<<o)<=n; ++o)
				if((i&(1<<o)) != (j&(1<<o))){
					cout << o+1; 
					break;
				}
			if(j == n) cout << endl; 
			else cout << ' '; 
		}
	return 0; 
}