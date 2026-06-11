#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep2(i,a,n) for(int i = (a);i < (n);i++)
#define rep(i,n) rep2(i,0,n)
#define INF (1LL << 60)
#define vec vector

int main(void){
    int n;ll k;
    cin >> n >> k;
    int a[n];
    vector<int> b(n);
    rep(i,n){
        cin >> a[i];
        a[i]--;
    }

    ll now = 0;
    ll ans = -1;
    vec<int> memo;
    for(ll i = 0;;i++){
        if(k == 0){
            ans = now+1;
            break;
        }
        
        b[now] = 1;
        now = a[now];
        k--;
        
        if(b[now] > 0){
            break;
        }
    }
    
    if(ans == -1){
        ll memo2 = now;
        while( 1 ){
            memo.push_back(now);
            now = a[now];
            if(now == memo2)break;
        }
        ans = memo[k % memo.size()]+1;
    }
    cout << ans << endl;
}