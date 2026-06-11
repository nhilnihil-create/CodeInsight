#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define se second
const int N = 2e5+5;
string s;
int n,k,cst[3];/// r = 0,s = 1,p = 2
int cnt[N];
void solve(){
    cin>>n>>k;
    for(int i=0;i<3;i++)cin>>cst[i];
    cin>>s;
    for(int i=0;i<n;i++){
        if(i<k)cnt[i] = 1;
        else {
            if(s[i]==s[i-k])cnt[i] = cnt[i-k]+1;
            else cnt[i] = 1;
        }
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        if(cnt[i]%2){
            if(s[i]=='r')ans+=cst[2];
            if(s[i]=='s')ans+=cst[0];
            if(s[i]=='p')ans+=cst[1];
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
   // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
