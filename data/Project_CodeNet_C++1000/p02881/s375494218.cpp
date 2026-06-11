#include <iostream>
#include <math.h>
using ll = long long;
using namespace std;

int main(){
    ll n, m=0, ans;

    cin >> n;

    for(ll i = sqrt(n); i>0; i--){
        if(n%i==0){
            m = i;
            break;
        }
    }

    ans = (m-1) + (n/m-1);
    cout << ans << endl;

    return 0;
}