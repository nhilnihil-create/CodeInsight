#include <iostream>
#include<vector>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define drep(i,n) for(int i = (n)-1; i >= 0; i--)
#define srep(i,s,t) for (int i = s; i < t; i++)
#define rng(a) a.begin(),a.end()
using ll = long long;

using namespace std;



int main() {
    int n;
    cin>>n;
    vector<int>a(n+1+1);
    rrep(i,n+1) cin>>a[i];
    vector<int>b(n+1+1);
    rrep(i,n) cin>>b[i];
    ll ans = 0;
    rrep(i,n+1) {
        if(a[i]>=b[i-1]) {
            ans += b[i-1];
            a[i] -= b[i-1];
        } else {
            ans += a[i];
            a[i] = 0;
        }
        if(a[i]>=b[i]) {
            ans += b[i];
            b[i] = 0;
        } else {
            ans += a[i];
            b[i] -= a[i];
            a[i] = 0;
        }
    }
    cout<<ans<<endl;

    return 0;
}
