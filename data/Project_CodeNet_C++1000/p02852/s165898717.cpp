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

ll N,M;
string S;
ll near0[100010];
int main(){
    cin>>N>>M>>S;
    for(ll i=0;i<=N;i++){
        near0[i]=i;
    }
    for(ll i=N-1;i>=N-M;i--){
        if(S[i]=='0'){
            near0[N]=i;
        }
    }
    for(ll i=N-1;i>M;i--){
        if(S[i-M]=='0'){
            near0[i]=i-M;
        }else{
            near0[i]=near0[i+1];
        }
    }
    for(ll i=M;i>=0;i--){
        near0[i]=0;
    }
    ll now=N;
    vector<ll> ans;
    while(now>0){
        if(near0[now]<now){
            ans.push_back(now-near0[now]);
            now=near0[now];
        }else{
            cout<<-1<<endl;
            return 0;
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto x:ans){
        cout<<x<<" ";
    }cout<<endl;
    return 0;
}