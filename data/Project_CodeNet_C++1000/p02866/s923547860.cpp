#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll

int n;
int num[100001];

main(){
	cin >> n;
	for(int i=0;i<n;i++){
		int d;
		cin >> d;
		num[d]++;
		if(i==0 && d!=0){
			cout << 0 << endl;
			return 0;
		}
	}

	int sum = 0;
	int ans = 1;
	for(int i=0;i<=100000;i++){
		if(num[0]!=1) break;
		if(i!=0){
			for(int j=0;j<num[i];j++){
				ans *= num[i-1];
				ans %= 998244353;
			}
		}
		sum += num[i];
	}
	if(sum!=n) ans = 0;

	cout << ans << endl;

	return 0;
}
