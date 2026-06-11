#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    ll n;
    cin >> n;
    
    if(n % 2 == 1)
        cout << 0 << endl;
    else {
        ll cnt = 0, fty = 10;
        while(n >= fty) {
            cnt += n / fty;
            fty *= 5;
        }
        
        cout << cnt << endl;
    }
    
    
    return 0;
}
