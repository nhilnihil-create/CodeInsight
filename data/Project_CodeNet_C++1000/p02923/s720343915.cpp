#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;



int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];

    int ans = 0;
    int tmp = 0;
    for(int i = 0; i < n-1; i++){
        if(h[i] >= h[i+1]){
            tmp++;
            ans = max(ans, tmp);
        }else{
            tmp = 0;
        }
    }

    cout << ans << endl;
    return 0;
}