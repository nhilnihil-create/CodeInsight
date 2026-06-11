#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<ll, ll> P;

ll func(ll x){
    ll res = 0;
    ll tmp = 1;
    while(x){
        tmp*=10;
        res+=tmp;
        x--;
    }
    return res;
}



int main(){

    ll n;
    cin >> n;
    
    ll ans = 0;
    for(ll i = 1; i <= n; i++){
        if(i/10==0){
            ans ++;
            continue;
        }
        ll now = i;
        ll l,r;
        ll o = 0;
        r = i%10;
        while(now/10>0){
            now /= 10;
            o++;
        }
        l = now;
        if(l==r){
            if(o==1){
                ans += 3;
            }else{
                ans += 5+func(o-2)*2;  
                ll tmp = 1;
                rep(j,o){
                    tmp*=10;
                } 
                // cout << (i- (l*tmp+l))/10 << endl;
                ans += ((i- (l*tmp+l))/10)*2;
            }
        }else if(l<r){
            if(o==1){
                continue;
            }else{
                ans += (1+func(o-2))*2;
            }
        }else if(r==0){
            continue;
        }else{
            ans += (1+func(o-1))*2;
        }
        // cout << "i :" << i << " ans :" << ans <<endl;
    }
    cout << ans << endl;


    return 0;
}