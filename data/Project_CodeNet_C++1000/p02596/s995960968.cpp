//Atcoder 177A
#include <bits/stdc++.h>
#define endl "\n"
#define int long long 

using namespace std;

int32_t main(){
	int k;
	cin >> k;
	int seven=7;
	for(int i=1;i<=k;i++){
		if(seven%k==0){
			cout << i << endl;
			return 0;
		}
		seven=seven%k;
		seven=seven*10+7;
	}
	cout << -1 << endl;
	return 0;
}