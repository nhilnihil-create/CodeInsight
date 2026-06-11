#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(ll)n;i++)


int main(){
    ll N; cin >> N;
    ll res = 0;

    if(N%2){
        cout << res << endl;
        return 0;
    }
    ll m = 10;
    while(m <= N){
        res += (N/m);
        m*=5;
    }
    cout << res << endl;

}