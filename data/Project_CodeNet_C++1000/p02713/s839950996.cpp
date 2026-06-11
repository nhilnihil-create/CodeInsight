#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

#define REP(i, n) for(ll i=0;i<ll(n); i++)


ll GCD(ll a, ll b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

int main(){
    int K;
    cin >> K;
    int i, j, k;
    ll ans = 0;
    ll gcd_1, gcd_2;
    for(i=1;i<=K;i++){
        for(j=1;j<=K;j++){
            for(k=1;k<=K;k++){
                gcd_1 = GCD(i, j);
                gcd_2 = GCD(gcd_1, k);
                /*
                if(i==j && j!=k){ans += 3*gcd_2;}
                if(i!=j && j==k){ans += 3*gcd_2;}
                if(i!=j && j!=k){ans +=   gcd_2;}
                if(i==j && j==k){ans +=   gcd_2;}
                cout << i << " " << j << " " << k << " " << gcd_2 << endl;
                */
                ans += gcd_2;

    }}}
    cout << ans << endl;

    return 0;
}
