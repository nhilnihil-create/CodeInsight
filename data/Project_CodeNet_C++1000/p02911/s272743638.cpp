
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    ll n, k, q;
    cin >> n >> k >> q;
    vector<ll> cnt(n,0);
    rep(i,q){
        ll a;
        cin >> a;
        cnt[a-1] ++;
    }
    for(int i=0; i<n; i++){
        if(cnt[i] > q-k){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }


}