#include <bits/stdc++.h>
using namespace std;

//kieutrave ten ham(tham so)
//s.substr(noibatdau,soluong)
int main(){
	long long a,b,c,k,tong;
	cin>>a>>b>>c>>k;
	if (a<k){
		k=k-a;
		tong=a;
	}
	else{
		tong=k;
		cout<<tong;
		return 0;
	}
	// a<k
	if (b<k){
		k=k-b;
	}
	else {
	cout<<tong;
	return 0;
}
// b<k
	if (c>=k){	
		tong=tong -k;
	}
	cout<<tong;
	return 0;
}