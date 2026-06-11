#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()


int main(){
    ll a,b,n;
    cin>>a>>b>>n;
    if(n<=b-1){
        ll ans=(a*n)/b-a*(n/b);
        cout<<ans<<endl;
    }
    else{
        ll ans=(a*(b-1))/b-a*((b-1)/b);
        cout<<ans<<endl;
    }

}

