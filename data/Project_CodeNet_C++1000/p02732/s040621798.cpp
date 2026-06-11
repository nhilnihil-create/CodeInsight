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
const ll INF=2e18;
const ll MOD=1e9+7;

ll N;
ll A[200010];
map<ll,ll> cnt;
int main(){
    cin>>N;
    for(ll i=0;i<N;i++){
        cin>>A[i];
        cnt[A[i]]++;
    }
    ll ans=0;
    for(auto p:cnt){
        ans+=p.second*(p.second-1)/2;
    }
    for(ll i=0;i<N;i++){
        cout<<ans-(cnt[A[i]]-1)<<endl;
    }

    return 0;
}