#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<(n);i++)
int n;
void input(){
	cin>>n;
	return;
}

void solve(){
	int m=n%1000;
	if(m!=0)m=1000-m;
	cout << m;
	return;
}
int main(){
	input();
	solve();
	return 0;
}