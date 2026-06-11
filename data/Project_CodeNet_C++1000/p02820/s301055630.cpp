#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define PI 3.1415926535897932384626433832795028841971693993
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;

int main(){
    int n,k,r,s,p,ans=0;
    string t;
    cin>>n>>k>>r>>s>>p>>t;
    vector<bool> dat(n,true);
    rep(i,n){
        if(i-k>=0){
            if(t[i-k]==t[i]&&dat[i-k]){
                dat[i]=false;
                continue;
            }
        }
        if(t[i]=='r') ans+=p;
        else if(t[i]=='s') ans+=r;
        else ans+=s;
    }
    cout<<ans<<endl;
    return 0;
}