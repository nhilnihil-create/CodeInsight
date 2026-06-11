#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n;
    cin >> n;
    vector<int> x(n),y(n);
    rep(i,n) cin >> x[i] >> y[i];
    vector<int> fact(n+1);
    fact[0] = 1;
    rep(i,n) fact[i+1] = fact[i]*(i+1);

    double ans = 0;
    for(int i=0; i<n; i++){
        for(int j= i+1; j<n; j++){
            ans += 2*fact[n-1]*sqrt( ((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j])) );
        }
    }
    printf("%.12lf\n",ans/fact[n]);
    return 0;
}