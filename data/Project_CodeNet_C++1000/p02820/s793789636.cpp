#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n,k,r,s,p;
    cin >> n >> k >> r >> s >> p;
    vector<char>t(n);
    for(ll i=0;i<n;i++){
        cin >> t[i];
    }
    ll ans=0;
    for(ll i=0;i<n;i++){
        if(t[i]=='r') ans+=p;
        if(t[i]=='s') ans+=r;
        if(t[i]=='p') ans+=s;
    }
    vector<ll>judge(n,-1);//0:r,1:s,2:p
    for(ll i=0;i<n-k;i++){
        if(t[i]=='r'&&t[i+k]=='r'&&judge[i]!=0){
            ans-=p;
            judge[i+k]=0;
        }
        if(t[i]=='s'&&t[i+k]=='s'&&judge[i]!=1){
            ans-=r;
            judge[i+k]=1;
        }
        if(t[i]=='p'&&t[i+k]=='p'&&judge[i]!=2){
            ans-=s;
            judge[i+k]=2;
        }
    }
    cout << ans << endl;
}