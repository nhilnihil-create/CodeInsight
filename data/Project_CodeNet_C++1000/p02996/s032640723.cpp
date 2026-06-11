#include <bits/stdc++.h>
#define FOR(i, l, r) for(ll i = l; i < r; i++)
#define rep(i, N) FOR(i, 0, N)
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<ll> vl;
const ll MOD = round(1e9+7);

int main() {
    int N; cin >> N;
    vector<P> BA(N); 
    rep(i,N) cin >> BA[i].second >> BA[i].first;
    sort(BA.begin(), BA.end());
    ll tmp = 0; bool flag = true;
    rep(i,N){
        //cout << i << endl;
        if(tmp + BA[i].second <= BA[i].first){
            tmp += BA[i].second;
        }else{
            flag = false;
            break;
        }
        
    }

    cout << (flag?"Yes":"No") << endl;
    return 0;
}
