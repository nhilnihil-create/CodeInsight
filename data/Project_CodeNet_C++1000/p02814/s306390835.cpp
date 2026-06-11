#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;

const ll INF=1LL<<60;
const int MOD=1e9+7;
const int N=2e5+5;

ll lcm2(ll a, ll b){
    ll d=__gcd(a, b);
    return a/d*b;
}

ll lcm(vector<ll> &arr){
    ll l=arr[0];
    for(int i=0; i<arr.size()-1; i++){
        l=lcm2(l, arr[i+1]);
    }
    return l;
}

int main(){
    int N, M; cin >> N >> M;
    vector<ll> arr(N);
    for(auto &x: arr) cin >> x;
    int cnt=0;
    bool ok=true;
    while(arr[0]%2 == 0 && ok){
        for(int i=0; i<N; i++){
            if(arr[i]%2 == 1){
                ok=false;
                break;
            }
            arr[i]/=2;
        }
        cnt++;
    }
    for(int i=0; i<N; i++){
        if(arr[i]%2 == 0) ok=false;
    }
    if(ok){
        ll val=lcm(arr)*pow(2, cnt-1);
        int res=0, k=1;
        if(val > 0){
            res=(M/val+1)/2;
        }
        cout << res << endl;
    }
    else cout << 0 << endl;
    return 0;
}