#include<iostream>
#include<iomanip>
#include<math.h>
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

string L;
ll dp[100010][2];
int main(){
    cin>>L;
    for(ll i=0;i<L.length();i++){
        for(ll j=0;j<2;j++){
                dp[i][j]=0;
        }
    }
    dp[0][0]=1;
    for(ll i=0;i<L.length();i++){
        for(ll j=0;j<2;j++){
            for(ll bit1=0;bit1<2;bit1++){
                for(ll bit2=0;bit2<2;bit2++){
                    if(bit1 && bit2)continue;
                    ll nextJ=j;
                    ll bit=bit1+bit2;
                    if(j==0){
                        if(bit>L[i]-'0')continue;
                        if(bit<L[i]-'0'){
                            nextJ=1;
                        }
                    }
                    dp[i+1][nextJ]=(dp[i+1][nextJ]+dp[i][j])%MOD;
                }
            }
        }
    }
    cout<<(dp[L.length()][0]+dp[L.length()][1])%MOD<<endl;
    return 0;
}