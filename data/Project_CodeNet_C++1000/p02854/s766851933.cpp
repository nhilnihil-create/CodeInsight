#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

double kaijyo(int n){
    int k(1);
    for(int i=n;i>0;i--){
        k *= i;
    }

    return k;
}

double distance(int x[],int y[],int i,int j){
    int dx = (x[i] - x[j]) * (x[i] - x[j]);
    int dy = (y[i] - y[j]) * (y[i] - y[j]);
    return sqrt(dx+dy);
}

int main(){
    int n;  cin >> n;
    ll a[n];    cin >> a[0];
    ll l(a[0]);
    for(int i=1;i<n;i++){
        cin >> a[i];
        l += a[i];
    }

    ll ans(l),sum(0);
    for(int i=0;i<n;i++){
        sum += a[i];
        ans = min(ans,abs(2*sum-l));
    }

    cout << ans << endl;

    return 0;
}