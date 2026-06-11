#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int a[n][2];
	for(int i=0; i<n; i++) cin >> a[i][0] >> a[i][1];
	
	for(int i=0; i+2<n; i++){
		if(a[i][0]==a[i][1] && a[i+1][0]==a[i+1][1] && a[i+2][0]==a[i+2][1]){
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	return 0;
}