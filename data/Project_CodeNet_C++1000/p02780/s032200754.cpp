#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
typedef long long ll;

int main() {
    int n,k;
    cin >> n >> k;
    vector<double> kitai(n);
    double ans = 0;
    rep(i,n){
        double p;
        cin >> p;
        double a = (p+1)/2;
        kitai[i]=a;
    }
    double now = 0;
    rep(i,k) now+=kitai[i];
    ans = now;
    rep(i,n-k){
        now-=kitai[i];
        now+=kitai[k+i];
        ans = max(ans,now);
    }    
    cout << fixed << setprecision(10) << ans << endl;
}