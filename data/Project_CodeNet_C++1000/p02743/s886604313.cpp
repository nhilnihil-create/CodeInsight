#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli a, b, c;

int main(void){
	cin >> a >> b >> c;
	if(c-a-b > 0 && a*a+b*b+c*c-2*a*b-2*b*c-2*c*a > 0) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
