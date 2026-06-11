#include <bits/stdc++.h>

using namespace std;

//typedef pair<int,int> P;
typedef long long ll; 

#define int ll


main(){
	int num[100]={0};

	int n,k;
	cin >> n >> k;
	for(int i=0;i<k;i++){
		int d;
		cin >> d;
		for(int j=0;j<d;j++){
			int a;
			cin >> a;
			num[a-1]++;
		}
	}

	int ans = 0;
	for(int i=0;i<n;i++){
		if(num[i]==0) ans++;
	}

	cout << ans << endl;

	return 0;
}