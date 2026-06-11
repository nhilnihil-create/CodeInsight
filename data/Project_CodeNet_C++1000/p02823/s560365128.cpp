#include<bits/stdc++.h>
using ll = long long;
using namespace std;

int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    
    ll ans = 0;
    if((b-a)%2==0){
        ans = (b-a) / 2;
    }else{
        ans = min(a-1, n-b) + 1 + (b-a-1)/2;
    }
    cout << ans << endl;
    return 0;
}