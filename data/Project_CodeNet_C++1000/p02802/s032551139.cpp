
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <utility>
#include <iomanip>
#include <queue>
#include <set>
#include <numeric>
#include <unordered_set>

#define rep(i,n) for(int i=0;i< (n);++i)
typedef long long ll;

using namespace std;


int main(){
    ll N,M;
    cin>>N>>M;
    
    vector<vector<ll> >vec(N+1,vector<ll>(2,0));
    
    for(ll i=0;i!=M;++i){
        ll n;
        cin>>n;
        string st;
        cin>>st;
        
        if(st=="AC"){
            if(vec[n][0]==0){
                vec[n][0]=1;
            }
            
        }else if(st=="WA"){
            if(vec[n][0]!=1){
                ++vec[n][1];
            }
        }
       // cout<<"vec["<<n<<"][0]"<<vec[n][0]<<":vec["<<n<<"][1]"<<vec[n][1]<<endl;
    }
    
    ll ans_ac=0;
    ll ans_wa=0;
    
    for(ll i=1;i<=N;++i){
        ans_ac+=vec[i][0];
        if(vec[i][0]==1){
            ans_wa+=vec[i][1];
        }
    }
    
    
    cout<<ans_ac<<" "<<ans_wa<<endl;
    
    
}

