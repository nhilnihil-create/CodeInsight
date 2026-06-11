#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main(){
	ll a,b,c,d;
	cin >> a >> b >> c >> d;
	ll res1 = max(a * d , b * c);
	ll res2 = max(a * c, b * d);
	ll res = max(res1,res2);
	if(a <= 0 && b >= 0){
		res = max(res,0ll);
	}
	if(c <= 0 && d >= 0){
		res = max(res,0ll);
	}
	cout << res;
	return 0;
}
