#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forin(in, n) for(int i=0; i<n; i++) cin>>in[i]
#define forout(out) for(int i=0; i<(int)out.size(); i++) cout<<out[i]<<" "
#define rep(i, n) for(int i=0; i<(n); i++)

int main(){
    ll n; cin>> n;
    ll nn = sqrt(n);
    ll ans=10000000000000;
    for(int i=1; i<=nn; i++){
        if(n % i == 0){
            ans = min(ans, n/i + i - 2);
        }
    }
    cout<< ans << endl;
}