#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void printv(vector<ll> v){
        for(ll elem : v) cout << elem << " ";
        cout << endl;
}

int main(void){
        ll n, k;
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
        //cout << "a = "; printv(a);
        //cout << "v = "; printv(v);
        if(k < (ll)v.size()){
                cout << v[k] << endl;
        } else {
                ll j;
                //printf("a[v.back()] = %lld\n", a[v.back()]);
                ll m = (ll)v.size();
                for(j = 0; j < m; j++){
                        //printf("j = %lld v[j] = %lld\n", j, v[j]);
                        if(v[j] == a[v.back()]){
                                if(j != 0){
                                        v.erase(v.begin(), v.begin()+j);
                                }
                                break;
                        } else {
                                //v.erase(v.begin());
                                //cout << "v = "; printv(v);
                        }
                }
                k -= j;
                //cout << "v = "; printv(v);
                cout << v[k%v.size()] << endl;
        }
        return 0;
}
