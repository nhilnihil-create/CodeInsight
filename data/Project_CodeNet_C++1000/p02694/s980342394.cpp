#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

int main(){
   ll x;
   cin >> x; 
   ll tmp = 100;
   ll ans = 0;
    while(tmp < x) {
        tmp += (tmp /100); 
        ans++;
    }
    cout << ans << endl; 
    return 0;
}