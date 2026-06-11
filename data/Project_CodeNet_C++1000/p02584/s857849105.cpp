#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    ll X, K, D;
    cin >> X >> K >> D;
    
    if(abs(X) > abs(K*D)){
        cout << abs(X)-abs((K*D)) << endl;
        return 0;
    }

    K=K-abs((X/D));
    X=abs(X)-abs((X/D)*D);

    if(K%2 == 1) X=abs(X-D);

    ll ans=abs(X);
    cout << ans << endl;
    return 0;
}