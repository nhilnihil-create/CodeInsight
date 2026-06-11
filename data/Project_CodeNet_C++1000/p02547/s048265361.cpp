#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string s;
int main(){
    ll n;
    cin >> n;
    ll a[n][2],cnt=0;
    for( ll i = 0; i < n; i++){
	cin >> a[i][0];
	cin >> a[i][1];
    }
    bool ok=false;
    for( ll i = 0; i + 2 < n; i++){
	if( a[i][0] == a[i][1] && a[i+1][0] == a[i+1][1] && a[i+2][0] == a[i+2][1] ){ok=true;}
    }
    puts(ok ? "Yes" : "No");



    return 0;
}
