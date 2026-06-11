#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;

LL LOG[100005];
LL pw2[100005];

void add_edge(LL u,LL v){
	cout << u << ' ' << v << endl;
}

int main(){
	LL n; cin >> n;
	LOG[0] = -1; for(LL i = 1;i <= n;i ++) LOG[i] = LOG[i >> 1] + 1;
	for(LL i = 1;i <= n;i ++) pw2[i] = (1LL << LOG[i]);
	if(n == pw2[n]){
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	add_edge(1,2); add_edge(2,3); add_edge(3,1 + n); add_edge(1 + n,2 + n); add_edge(2 + n,3 + n);
	for(LL i = 4;i + 1 <= n;i += 2){
		add_edge(i,1); add_edge(i + 1,1);
		add_edge(i + n,i + 1); add_edge(i + n + 1,i);
	}
	if(!(n & 1)){
		add_edge(pw2[n] + 1,n);
		add_edge(n - pw2[n],n + n);
	}
	return 0;
}
//