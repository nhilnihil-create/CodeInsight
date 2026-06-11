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

ll T1,T2,A1,A2,B1,B2;
int main(){
    cin>>T1>>T2>>A1>>A2>>B1>>B2;
    ll abs1=T1*(A1-B1);
    ll abs2=T2*(A2-B2);
    if(abs1+abs2==0){
        cout<<"infinity";
        return 0;
    }
    if(abs1>0){
        abs1*=-1;
        abs2*=-1;
    }
    if(abs1+abs2<0){
        cout<<0;
        return 0;
    }
    cout<<-abs1/(abs1+abs2)*2+(-abs1%(abs1+abs2)!=0);
    return 0;
}