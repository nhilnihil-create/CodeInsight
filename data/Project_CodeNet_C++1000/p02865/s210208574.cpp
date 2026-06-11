#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i <(n) ; ++i)
#define PI 3.14159265
using namespace std;
using ll = long long;
void self_max(int &a,int b){
	a = max(a,b);
}
void self_min(ll &a,ll b){
	a = min(a,b);
}
int main(){
	int n; cin >> n;
	int ans = 0;

	if(n&1){
		cout << n/2 << endl;
	}else{
		cout << n/2-1 << endl;
	}
	return 0;
}
