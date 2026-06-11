#include <iostream>

using namespace std;

int dp[260000]={0};

int main(){
	for(int i=2; i<260000; i++){
		bool flag = true;
		for(int j=2; j<i; j++){
			if(i%j==0){
				flag = false;
				break;
			}
		}
		if(flag) dp[i]=1;
	}
	dp[2]=1;

	while(1){
		int n; cin >> n;
		if(!n) break;
		int count=0;
		for(int i=n+1; i<=2*n; i++){
			count+=dp[i];
		}
		cout << count << endl;
	}
	return 0;
}
