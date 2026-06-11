#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()

int main(){
    int N,M;cin>>N>>M;
    vector<priority_queue<int>>connected(N);
    vector<int>H(N);
    int a,b;
    int ans=0;
    rep(i,N){
        cin>>H.at(i);
    }
    rep(i,M){
        cin>>a>>b;
        connected.at(a-1).push(H.at(b-1));
        connected.at(b-1).push(H.at(a-1));
    }
    rep(i,N){
        if(connected.at(i).empty()){
            ans++;
        }else if(H.at(i)>connected.at(i).top()){
            ans++;
        }
    }
    cout<<ans<<endl;


}
