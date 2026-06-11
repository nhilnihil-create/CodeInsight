#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#define rep(i, n)   for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int n;  
ll k;   
vector<ll>a;

bool check(ll x){
    ll tmp = 0;
    rep(i, n){
        tmp += (a[i]-1)/x;
        if(tmp > k) return false;
    }
    return true;
}

ll solve(){
    ll ok = 10000000000, ng = 0;
    while(ng < ok - 1){
        ll ptr = (ok+ng)/2;
        if(check(ptr))  ok = ptr;
        else            ng = ptr;
    }
    return ok;
}

int main(){
    cin >> n;
    cin >> k;
    a.resize(n);
    rep(i, n)   cin >> a[i];
    cout << solve() << endl;
}
