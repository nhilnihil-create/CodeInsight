#include <bits/stdc++.h>
#define ll long long int
#define forr(i,n) for(ll i=0;i<n;i++)
#define mod 1000000007
#define oo 2000000000000000000LL
using namespace std;

ll n,k;
ll p[5500] , c[5500];

ll get(ll i){
    ll next = p[i] , sum=0LL , cycle_cnt = 0;
    i = next ;
    while(1){
        sum +=c[next];
        next = p[next];
        cycle_cnt++;
        if(next==i) break;
    }
    ll ans = -oo, cnt = 0 , path=0;
    while(1){
        cnt++;
        path += c[next];
        if( cnt > k ) break;
        else{
            ans = max(ans , path);
            ll tot = ( k - cnt )/cycle_cnt;
            tot = path + max(0LL , sum)*tot;
            ans = max(ans , tot);
        }
        next = p[next];
        if(next == i) break;
    }
    return ans;
}

void _sol(){
    cin >> n >> k;
    forr(i,n) cin >> p[i] , p[i]--;
    forr(i,n) cin >> c[i];
    ll ans = -oo;
    for(ll i=0LL;i<n;i++){
        ans = max(ans , get(i));
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    _sol();
}
