#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	long long X,K,D,E;
	cin>>X;
	cin>>K;
	cin>>D;
	X=abs(X);
	long long ans;

	if(X/D>=K){
		ans=X-K*D;
	}else{
		E=X/D;
		K=K-E;
		X=X-E*D;
		if(K%2!=0){
			ans=abs(X-D);
		}else{ans=X;}
	}
	cout<<ans<<endl;
}