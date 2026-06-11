#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;

    int d[n];
    map<int, int> m;
    for(int i = 0; i < n; i++){
        cin >> d[i];
        auto itr = m.find(d[i]);
        if(itr == m.end()){
            m[d[i]] = 1;
        }else{
            m[d[i]]++;
        }
    }

    int now = 0;
    int bef = 1;
    ll ans = 1;
    ll q = 998244353;

    for(auto itr = m.begin(); itr != m.end(); ++itr){
        if(itr->first != now){
            ans = 0;
            break;
        }else{
            ll t = 1; 
            for(int i = 0; i < itr->second; i++){
                t *= bef;
                t %= q;
            }
            ans *= t;
            ans %= q;
            bef = itr->second;
            now++; 
        }
    }

    auto itr = m.find(0);
    if(itr != m.end()){
        if(m[0] != 1){
            ans = 0;
        }
    }

    if(d[0] != 0){
        ans = 0;
    }

    cout << ans << endl;
}