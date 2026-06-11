#include <bits/stdc++.h>
using namespace std;
#define rep(i, seisu) for(int i = 0; i < (int)(seisu); i++)

typedef long long ll;
///vector<pair<string, int>>;

int main(){
 ll a, b, c, d;
 cin >> a >> b >> c >> d;
 ll cn, dn, cd, both;
 ll zero =0;
 cn = max(b/c, zero)-max((a-1)/c,zero);  //a~bのうちのcの倍数
 dn = max(b/d, zero)-max((a-1)/d, zero); //a~bのうちのdの倍数
 cd = c * d / gcd(c, d);
 both = max(b/cd,zero)-max((a-1)/cd, zero); //a~bのうちのc*dの倍数
 ll ans = (b - a+1) - (cn + dn - both);
 cout << ans << endl;
}


