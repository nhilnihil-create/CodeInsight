#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
int main(){
    cout << setprecision(20);
    int n,k;
    cin >> n >> k;
    long double p[n];
    rep(i,n){
        double a;
        cin >> a;
        p[i] = 1+a;
        p[i] /= 2;
    }
    rep(i,n-1)p[i+1] = p[i] + p[i+1];
    long double ans = p[k-1];
    
    rep(i,n-k){
        ans = max(ans,p[i+k]-p[i]);
    }
    cout << ans << endl;
    //rep(i,n)cout << p[i] << endl;
    return 0;
}