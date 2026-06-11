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
ll d[100010];
int main(){
    cin>>N;
    for(ll i=0;i<N;i++)cin>>d[i];
    sort(d,d+N);
    cout<<d[N/2]-d[N/2-1]<<endl;
    return 0;
}