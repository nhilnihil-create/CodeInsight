#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    ll dif = 1e12, front = 0, back = 0;
    int n; cin >> n;
    vector<ll> a(n); rep(i,n) cin >> a.at(i);

    back = accumulate(a.begin(),a.end(),0LL);

    for(int i = 0; i < n; i++){
        front += a.at(i);
        back -= a.at(i);
        if(abs(back - front) < dif){
            dif = abs(back - front);
        }
    }
    
    put(dif);
}