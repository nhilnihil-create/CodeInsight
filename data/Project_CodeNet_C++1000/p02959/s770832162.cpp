#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector<int> a(n+1), b(n);
    ll sum = 0;
    rep(i,n+1){
        cin >> a[i];
        sum += a[i];
    }
    rep(i,n) cin >> b[i];

    rep(i,n){
        if(b[i] >= a[i]){
            b[i] -= a[i];
            a[i] = 0;
            a[i+1] = max(a[i+1]-b[i], 0);
        }
        else{
            a[i] -= b[i];
        }
    }
    
    ll cnt = 0;
    rep(i,n+1) cnt += a[i];
    cout << sum - cnt << endl;  
}