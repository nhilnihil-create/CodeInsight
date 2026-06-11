#include<bits/stdc++.h>
 
#define rep(i,n) for(ll i = 0;i < n;++i)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
typedef pair<int,int> P;
 
const int INF = 1001001001;
const long double PI = (acos(-1));
const int mod = 1e9+7;
const int vx[6] = {0,1,0,-1,1,-1};
const int vy[6] = {1,0,-1,0,1,1};



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<int> h(n);
    rep(i,n){
        cin >> h[i];
    }
    reverse(all(h));
    int maxv = h[0];
    rep(i,n){
        if(h[i] > maxv) {
            h[i]--;
            if(h[i] > maxv) {
                cout << "No" << endl;
                return 0;
            }
            maxv = h[i];
        }else {
            maxv = h[i];
        }
    }
    cout << "Yes" << endl;
    cout << endl;
    return 0;
}
