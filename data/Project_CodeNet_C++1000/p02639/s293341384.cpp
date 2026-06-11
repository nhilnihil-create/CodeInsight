#include<iostream>
using namespace std;

int main(){
	int N=5, x[N+1], i, ans;
	for(i=1; i<=N; i++){
		cin >> x[i];
	}
	for(i=1; i<=N; i++){
		if(x[i]==0)	ans=i;
	}
	
	cout << ans << endl;
	return 0;
}
