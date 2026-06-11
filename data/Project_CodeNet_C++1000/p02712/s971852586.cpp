#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

#define REP(i, n) for(ll i=0;i<ll(n); i++)

int main(){
    ll a;
    cin >> a;
    ll ans = 0;
    for(int i=1;i<=a;i++){
        if(i % 3 != 0 && i % 5 != 0){ans += i;}
        else{continue;}
    }
    cout << ans << endl;

    return 0;
}
