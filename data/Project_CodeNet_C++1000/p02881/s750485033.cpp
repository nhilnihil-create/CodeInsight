#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    ll n;
    cin >> n;
    ll d=1,e;
    for(ll i=2; i*i<=n; i++){
        if(n%i==0){
            d = i;
        }
    }
    e = n/d;
    cout << (d+e-2) << endl;
    

    return 0;
}
