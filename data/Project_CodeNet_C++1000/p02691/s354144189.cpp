#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;

    ll a[n];
    map<ll, int> l;
    map<ll, int> r;
    ll max = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        ll k = (i + 1) - a[i];
        auto itr = l.find(k);
        if(itr == l.end()){
            l[k] = 1;
        }else{
            l[k]++;
        }
    }

    ll ans = 0;

    for(int i = 0; i < n; i++){
        ll k = (i + 1)+ a[i];
        auto itr = l.find(k);
        if(itr != l.end()){
            ans += itr->second;
        }
    }

    cout << ans << endl;
}