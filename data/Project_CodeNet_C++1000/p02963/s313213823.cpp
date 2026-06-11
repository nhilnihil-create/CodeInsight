// AtCoder template
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < n; ++i)


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    const ll r_lim = 1e9;
    ll s; cin >> s;
    ll a1 = (s/r_lim)*r_lim, a2 = s%r_lim;
    ll x1,x2,y1,y2;
    if(a1 == 0){
        x1 = 0; y2 = 1;
        x2 = a2; y1 = 1;
    }else if(a2 == 0){
        x1 = r_lim; y2 = s/r_lim;
        x2 = 0; y1 = 1;
    }else{
        x1 = r_lim;
        y2 = s/r_lim+1;
        a2 = (s/r_lim+1)*r_lim-s;
        x2 = a2; y1 = 1LL;
    }

    cout << "0 0 " << x1 << " " << y1 << " " << x2 << " " << y2 << endl; 
}
