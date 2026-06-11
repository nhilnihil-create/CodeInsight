#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
    int a,b,m;
    ll ans;ll yasui=1000000000000;
    int reizo_m=1000000,densi_m=1000000;
    cin >> a >> b >> m;
    vector<int>reizo(a);
    vector<int>densi(b);
    rep(i,a){
        cin >> reizo[i];
        reizo_m = min(reizo[i],reizo_m);
    }
    rep(i,b){
        cin >> densi[i];
        densi_m = min(densi[i],densi_m);
    }
   
    ll j=densi_m + reizo_m;
    rep(i,m){
        int x,y,c;
        
        ll nedan=0;

        cin >> x >> y >> c;
        nedan = reizo[x-1] + densi[y-1] - c;
        yasui = min(yasui,nedan);
        
    }
    cout << min(yasui,j) << endl;
    return 0;
}