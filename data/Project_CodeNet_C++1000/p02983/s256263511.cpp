#include<iostream>
#include<iomanip>
#include<cassert>
#include<math.h>
#include<complex>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<unordered_map>
#include<functional>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=4e18+1;
const ll MOD=1e9+7;

ll L,R;
int main(){
    cin>>L>>R;
    if(R-L>=2019){
        cout<<0<<endl;
        return 0;
    }
    ll ans=INF;
    for(ll i=L;i<=R;i++){
        for(ll j=i+1;j<=R;j++){
            ans=min(i*j%2019,ans);
        }
    }
    cout<<ans<<endl;

    return 0;
}