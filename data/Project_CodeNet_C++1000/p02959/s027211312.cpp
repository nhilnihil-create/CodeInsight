
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int n;
    cin >> n;
    vector<int> a(n+1), b(n);
    rep(i,n+1) cin >> a[i];
    rep(i,n) cin >> b[i];

    ll save=0;
    rep(i,n+1){
        save += min(a[i]+a[i+1],b[i]);
        a[i+1] -= max(0,b[i]-a[i]);
        if(a[i+1]<0) a[i+1]=0;
    }

    cout << save << endl;
}