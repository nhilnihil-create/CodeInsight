#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli h;
lli attack(lli x){
	if(x == 1) return 1;
	return 2*attack(x/2)+1;
}

int main(void){
	cin >> h;
	cout << attack(h) << endl;
	return 0;
}
