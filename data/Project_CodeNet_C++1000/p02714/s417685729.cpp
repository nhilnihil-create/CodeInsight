#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<ll> >;

const ll INF = 1e18;
const ll MOD = 1000000007;
const ll MX = 0; //最大値

#define rep(i,n) for(ll i=0; i<(ll)(n); i++)
#define ALL(x) (x).begin(),(x).end()
#define MAX(x) *max_element(ALL(x))
#define PB push_back
#define F first
#define S second

int main(){
    ll n; string s;
    cin >> n >> s;
    ll R = 0,G = 0,B = 0, cnt = 0;
    rep(i, n){
        if(s[i] == 'R') R++;
        else if(s[i] == 'G') G++;
        else if (s[i] == 'B') B++;
    }

    for(int i = 0; i < n-2; i++){
        for(int j = 1; i + j * 2 < n; j++){
               if(s[i] != s[i+j] && s[i+j] != s[i+j*2] && s[i] != s[i+j*2]) cnt++;
        }
    }

    cout << R*G*B - cnt << endl;
    return 0;
}