#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll t1,t2,a1,a2,b1,b2;
	cin>>t1>>t2>>a1>>a2>>b1>>b2;
	if(a1<b1){
		swap(a1,b1);
		swap(a2,b2);
	}
	ll ma=(a1-b1)*t1;
	ll mi=ma+t2*(a2-b2);
	if(mi==0){
		cout<< "infinity";
	}
	else if(mi>0){
		cout << 0;
	}
	else{
		mi=abs(mi);
		if(ma%mi==0){
		//	cout << "k";
			cout << 2*(ma/mi);
		}
		else{
			cout << 1+2*(ma/mi);
		}
	}
	// your code goes here
	return 0;
}