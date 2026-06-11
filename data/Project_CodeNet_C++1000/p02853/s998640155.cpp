#include <bits/stdc++.h>
using namespace std;

int main(){
	int X,Y;
	cin >> X >> Y;
	
	int ans=0;
	for(int i=1;i<=3;i++){
		if(X<=i)ans+=100000;
		if(Y<=i)ans+=100000;
	}
	if(X*Y==1)ans+=400000;
	
	cout << ans << endl;
	return 0;
}