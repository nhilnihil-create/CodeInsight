#include<bits/stdc++.h>
using namespace std;
int main(){
	long long int X,K,D;
	cin >> X >> K >> D;
	long long int answer=0;
	X=abs(X);
	if(X/D>=K){
		answer=abs(X-K*D);
	}
	else if(X/D<K){
		int value=(X/D);
		if((K-value)%2==0){
			answer=abs((X-(value)*D));
		}
		else{
			answer=abs((X-(value+1)*D));
		}
	}
	cout << answer << endl;
}