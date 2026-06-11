#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define cans cout << ans << endl
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
typedef long long ll;


int main(){
    int n;
    cin >> n;
    vector<int> a(n+1),b(n);
    rep(i,n+1) cin >> a[i];
    rep(i,n) cin >> b[i];
    ll sum = 0;
    rep(i,n+1) sum += a[i];
    for(int i=n; i>0; --i){
        if(a[i]-b[i-1] >= 0){
            a[i] -= b[i-1];
            b[i-1] = 0;
        }else{
            b[i-1] -= a[i];
            a[i] = 0;
        }
        if(a[i-1]-b[i-1] >= 0){
            a[i-1] -= b[i-1];
            b[i-1] = 0;
        }else{
            b[i-1] -= a[i-1];
            a[i-1] = 0;
        }
    }
    ll now = 0;
    rep(i,n+1) now += a[i];
    cout << sum - now << endl;

    return 0;
}