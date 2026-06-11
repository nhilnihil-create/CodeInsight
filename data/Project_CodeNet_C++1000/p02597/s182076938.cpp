#include <bits/stdc++.h>

using namespace std;

//typedef pair<int,int> P;
typedef long long ll; 

#define int ll


main(){
	int n;
	char c[200001];
	cin >> n >> c;

	int ans = 0;
	int l=0,r=n-1;
	while(l<r){
		if(c[l]=='W' && c[r]=='R'){
			swap(c[l],c[r]);
			ans++;
		}
		if(c[l]=='R')l++;
		if(c[r]=='W')r--;
	}


	cout << ans << endl;

	return 0;
}