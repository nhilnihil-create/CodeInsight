#include <bits/stdc++.h>
#define ENDL '\n'
#define io ios_base::sync_with_stdio(false);cin.tie(0);
#define sayy cout<<"YES"<<ENDL;
#define sayn cout<<"NO"<<ENDL;

typedef long long ll;
using namespace std;

int main(){
    io

    ll n,ans(0);
    cin >> n;

    for(int i(1); i<=n; i++){
        string s = to_string(i);
        if(s.length() % 2 == 1) ans++;
    }
    cout << ans << ENDL;
    return 0;
}
