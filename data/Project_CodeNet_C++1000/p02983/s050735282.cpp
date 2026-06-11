#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long mod = 2019;
int main(){
ll l,r;
cin >> l >> r;
if(r-l>=2018) cout << 0;
else{
        ll mini = INT_MAX;
    for(ll i = l;i<r;i++){
        for(ll j = i+1;j<=r;j++){
            mini = min(mini,i*j%2019);
        }
    }
cout << mini;
}
return 0;
}