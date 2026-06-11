#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    ll a, b, k;
    cin >> a >> b >> k;
    
    if(a < k) {
        k -= a;
        a = 0;
        
        b -= k;
        if(b < 0)
            b = 0;
    }
    else {
        a -= k;
    }
    
    cout << a << " " << b << endl;
    
    
    
    return 0;
}


