#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
	
ll mod = 1e9 + 7;
 
int main(){
    ll n; cin >> n;
    string ans = "";
    while(n > 0){
        n--;
        char tmp = (n % 26) + 'a';
        n /= 26;
        ans += tmp;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
    
    return 0;
}
