#include <bits/stdc++.h>

using namespace std;

//typedef pair<int,int> P;
typedef long long ll; 

#define int ll

int c[12];
int a[12][12];

main(){
	int n,m,x;
	cin >> n >> m >> x;
	for(int i=0;i<n;i++){
		cin >> c[i];
		for(int j=0;j<m;j++){
			cin >> a[i][j];
		}
	}

	int ans = 1e10;
	for(int i=0;i<(1 << n); i++){
		int sum = 0;
		int s[12]={0};
		for(int j=0;j<n;j++){
			if(((i&(1<<j))>>j)){
				sum += c[j];
				for(int k=0;k<m;k++) s[k] += a[j][k];
			}
		}
		bool ok = true;
		for(int j=0;j<m;j++){
			if(s[j]<x) ok = false;
		}
		if(ok){
			ans = min(ans, sum);
		}
	}

	if(ans == 1e10){
		cout << "-1" << endl;
	}else{
		cout << ans << endl;
	}

	return 0;
}