#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    ll sum = a+b;

    if(n%sum == 0){
        cout << n/sum * a;
        return 0;
    }
    else{
        ll ans=0;
        ans = n/sum * a;
        n = n%sum;
        ans += min(a, n);
        cout << ans;
        return 0;
    }

    return 0;
}