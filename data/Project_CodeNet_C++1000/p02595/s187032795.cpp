#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
#define INF 999999999
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

using llong = long long;
using namespace std;

int main(){
    llong N,ans=0;
    double D,X[200100],Y[200100];
    cin >> N >> D;
    rep(i,N) {
        cin >> X[i] >> Y[i];
        if(sqrt(X[i]*X[i]+Y[i]*Y[i]) <= D) ans++;
    }
    
    cout << ans << endl;
    return 0;
}