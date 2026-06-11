#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MOD ll(1e9+7)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cerr<<#x<<": "<<x<<endl

int main(){
    ll t1, t2, a1, a2, b1, b2;
    cin >> t1 >> t2;
    cin >> a1 >> a2;
    cin >> b1 >> b2;

    if(t1*a1+t2*a2 == t1*b1+t2*b2){
        cout << "infinity" << endl;
        return 0;
    }else if(t1*a1>t1*b1 && t1*a1+t2*a2>t1*b1+t2*b2){
        cout << 0 << endl;
        return 0;
    }else if(t1*a1<t1*b1 && t1*a1+t2*a2<t1*b1+t2*b2){
        cout << 0 << endl;
        return 0;
    }

    ll init = abs(t1*(a1-b1));
    ll diff = abs(t1*(a1-b1)+t2*(a2-b2));
    ll ans = (init/diff)*2;
    if(init%diff != 0){ans++;}
    cout << ans << endl;
    return 0;

}
