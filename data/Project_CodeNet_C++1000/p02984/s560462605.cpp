#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a.at(i);
    }
    ll a1=0;
    for(int i=0;i<n;i++){
        if(i%2==0){
            a1 += a.at(i);
        }else {
            a1 -= a.at(i);
        }
    }
    cout << a1;
    ll cur = a1;
    rep(i,n-1){
        cur = a.at(i)*2-cur;
        cout << " " << cur;
    }
    cout << endl;
    return 0;
}