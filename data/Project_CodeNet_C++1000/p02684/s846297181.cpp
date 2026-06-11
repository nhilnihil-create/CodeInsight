#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
        ll n, k, ans;
        cin >> n >> k;
        vector<ll> a(n+1);
        for(int i = 1; i <= n; i++) cin >> a[i];
        vector<ll> v;
        vector<bool> b(n+1, false);
        ll i = 1;
        while(!b[i]){
                v.push_back(i);
                b[i] = true;
                i = a[i];
        }
        if(k < (ll)v.size()){
                ans = v[k];
        } else {
                ll j;
                ll m = (ll)v.size();
                for(j = 0; j < m; j++){
                        if(v[j] == a[v.back()]){
                                v.erase(v.begin(), v.begin()+j);
                                break;
                        }
                }
                k -= j;
                ans = v[k%v.size()];
        }
        cout << ans << endl;
        return 0;
}
