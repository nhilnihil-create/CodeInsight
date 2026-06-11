#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n, m; cin >> n >> m;
    vector<ll> wa(n, 0), ac(n, 0);
    ll a = 0, w = 0;
    for(int i=0; i<m; ++i){
        int p; string s;
        cin >> p >> s ; p--;
        if(s=="AC"){
            if(!ac[p]){
                a++; ac[p] = 1;
                w += wa[p];
            }
        }else{
            wa[p]++;
        }
    }
    cout << a << ' ' << w << endl;
    return 0;
}