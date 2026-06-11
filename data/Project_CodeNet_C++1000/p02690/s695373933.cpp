#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()


int main(){
    ll x;
    cin>>x;
    for(ll i=-1000;i<=1000;i++){
        for(ll j=-1000;j<=1000;j++){
            if(i*i*i*i*i-j*j*j*j*j==x){
                cout<<i<<" "<<j<<endl;
                return 0;
            }
        }
    }
}

