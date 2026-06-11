#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

int x;

int main(void){
	cin >> x;
	int r = x%100;
	int t = 0;
	for(int i = 5; i >= 1; i--){
		t += r/i;
		r%=i;
	}
	if(100*t > x) cout << 0 << endl;
	else cout << 1 << endl;
	return 0;
}
