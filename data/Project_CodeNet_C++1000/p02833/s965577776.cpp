#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main(){
    ll n;
    cin >>n;
    if(n%2){
        cout << 0 << endl;
        return 0;
    }

    ll k = n/2;
    ll ans = 0;
    while(k >= 5){
        ans += k/5;
        k /= 5;
    }

    cout << ans << endl;

}