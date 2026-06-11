#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
ll mod = 1e9 + 7;

int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n + 5);
    for(ll i = 1; i <= n; ++i){
        cin >> v[i];
    }
    ll arr[200001] = {0};
    ll r = 0, ans, cur = 1, kanta = k;
    for(ll i = 1; i <= n; ++i){
        ans = cur;
        if(arr[ans] == true){
            break;
        }
        cur = v[ans];
        kanta--;
        if(kanta == 0){
            cout << cur;
            return 0;
        }
        arr[ans] = true;
    }
    memset(arr, 0, sizeof(arr));
    ll fuckme = ans;
    cur = ans; // pocetak cycle,  v1.size() cycle len
    vector<ll> v1;
    ll tmp = 0;
    for(ll i = 1; i <= n; ++i){
        ans = cur;
        if(arr[ans] == true){
            break;
        }
        v1.push_back(cur);
        cur = v[ans];
        arr[ans] = true;
    }
    cur = 1;
    for(ll i = 0; i < v.size(); ++i){
        cur = v[cur];
        if(v1[0] == cur){
            tmp = i + 1; // before cycle
            break;
        }
    }
    k -= tmp;
    k %= v1.size(); 
    cur = fuckme;
    while(k){
        cur = v[cur];
        k--;
    }
    cout << cur;
    return 0;
 
}
