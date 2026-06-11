#include <bits/stdc++.h>
#define ll long long
#define pq priority_queue
using namespace std;
const ll INF=(ll)1e9;
const ll MOD=(ll)1e9+7;
const ll MAX=510000;
vector<int> dx={1,0,-1,0},dy={0,1,0,-1};
template<class T> inline bool chmax(T& a, T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
    string S;
    ll K,cnt=0,ans=0;
    cin>>S>>K;
    for(ll i=0;i<S.size();i++){
        cnt++;
        if(S[i]!=S[i+1]||S.size()-1==i){
            if(cnt==S.size()){
                cout<<cnt*K/2<<endl;
                return 0;
            }
            ans+=cnt/2*K;
            cnt=0;
        }
    }
    if(S[0]==S[S.size()-1]){
        ll l,r;
        for(l=0;l<S.size();l++){
            if(S[l]!=S[l+1]) break;
        }
        l++;
        for(r=S.size()-1;r>=0;r--){
            if(S[r]!=S[r-1]) break;
        }
        r=S.size()-r;
        ans-=(l/2+r/2-(l+r)/2)*(K-1);
    }
    cout<<ans<<endl;
}
