#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
    ll t1, t2, a1, a2, b1, b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    ll d1=(a1-b1)*t1, d2=(a2-b2)*t2;
    if(d1>0){
        d1*=-1, d2*=-1;
    }

    if(d2<0) cout << 0 << endl;
    else if(d1+d2==0) cout << "infinity" << endl;
    else if(d1+d2<0) cout << 0 << endl;
    else{
        ll ans=2*(ll)((-d1)/(d1+d2));
        if((-d1)%(d1+d2)!=0) ans++;
        cout << ans << endl;
    }
    return 0;
}