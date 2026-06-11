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

ll A,B,K;
int main(){
    cin>>K>>A>>B;
    for(ll i=A;i<=B;i++){
        if(i%K==0){
            cout<<"OK"<<endl;
            return 0;
        }
    }
    cout<<"NG"<<endl;

    return 0;
}