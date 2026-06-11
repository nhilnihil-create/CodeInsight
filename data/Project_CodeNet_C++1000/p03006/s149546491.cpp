#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;


int main(){
    int n;  cin >> n;
  
    vector<ll> x(n), y(n);

    for(int i=0; i<n; i++) cin >> x.at(i) >> y.at(i);

    ll res=n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j) continue;
            ll dx = x[j]-x[i], dy=y[j]-y[i];

            ll sub=0;
            for(int i2=0; i2<n; i2++){
                for(int j2=0; j2<n; j2++){
                    if(i2==j2) continue;
                    if(x[i2]+dx==x[j2] && y[i2]+dy==y[j2]) sub += 1;
                }
            }
            res = min(res, n-sub);
        }
    }

    cout << res << endl;


}