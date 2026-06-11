#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

#define REP(i, n) for(ll i=0;i<ll(n); i++)

int main(){
    ll A, B, C, K;
    cin >> A >> B >> C >> K;

    ll ans = 0;
    int i;
    if(K <= A){ans += K;}
    else if(K <= (A + B)){ans += A;}
    else{ans += A; ans += (A + B - K);}

    cout << ans << endl;

    return 0;
}
