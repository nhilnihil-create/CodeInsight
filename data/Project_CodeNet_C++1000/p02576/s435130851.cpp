#include <bits/stdc++.h>

using namespace std;

int main (){
	
	int N,X,T;
	cin >> N >> X >> T;
	int ans=0;
	while (N>0){
		N-=X;
		ans += T;
	}
	
	cout << ans;
}