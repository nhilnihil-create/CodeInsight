#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>

using namespace std;

#define ll long long
#define rep(i, n) for(ll i = 0; i < n; i++)
#define P pair<int, int>

typedef vector<int> vec;
typedef vector<vec> mat;

int main(){
    ll k;
    cin >> k;
    ll l;
    if(k % 2 == 0 || k % 5 == 0){
        cout << -1 << endl;
        return 0;
    }else if (k % 7 == 0){
        l = (9 * k) / 7;
    }else{
        l = 9 * k;
    }
    ll mod = 10;
    ll ans = 0;
    // cout << l << endl;
    while(true){
        ans++;
        if(mod % l == 1) break;
        mod %= l;
        mod *= 10;
        // cout << mod << endl;
    }
    cout << ans << endl;
}