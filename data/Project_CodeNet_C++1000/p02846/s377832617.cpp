#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    ll T1, T2, A1, A2, B1, B2;
    cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
    ll alpha = T1*(A1-B1) + T2*(A2-B2);
    ll beta = T2*(A2-B2);

    if(alpha == 0){
        cout << "infinity" << endl;
    }else{
        ll ans = max(0ll, beta/alpha) + max(0ll, ll(1.0*beta/alpha-1));
        if(beta%alpha==0) ans--; 
        cout << max(0ll, ans) << endl;
    }
}