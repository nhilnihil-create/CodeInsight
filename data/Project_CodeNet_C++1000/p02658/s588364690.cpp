#include <bits/stdc++.h>
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
typedef long long ll;
using namespace std;

int main(){
    int n;
    ll ans = 1;
    cin >> n ;
    
    bool over = false;
    bool zero = false;
    rep(i, n){
        ll a;
        cin >> a;
        if(a==0){
            zero=true;
            ans = 0;
            continue;
        }
        if(ans > 1000000000000000000/a){
            ans = -1;
            over = true;
        }else{
            ans *= a;
        }
        
        if(a==0)zero=true;
    }
    
    if(!zero && over)ans = -1;
    cout << ans << endl;
}