#include <bits/stdc++.h>
using namespace std;
long long a , b , c , d , ans;
int main(){
	cin>> a>> b >> c >> d;
	ans=max(a * c, a * d);
    ans=max( ans , b * c);
    ans=max( ans , b * d);
	cout << ans << '\n'  ;
}