#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
typedef long long ll;
ll a, b, c;
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> a >> b >> c;
	if(c-a-b>=0&&(c-a-b)*(c-a-b)>4*a*b){
		cout << "Yes" << nl;
	}else{
		cout << "No" << nl;
	}
	return 0;
}