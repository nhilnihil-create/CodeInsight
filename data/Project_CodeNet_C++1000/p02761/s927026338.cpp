// Hail god Yato
 
#include <bits/stdc++.h> 
using namespace std;
 
#define hs ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll MOD = 1000000007;
const ll INF = 1e18;
const ll MAX = 100001;
//
//
void solve(){
    int n, m;
    cin>>n>>m;
    string ans = string(n, '*');
    while(m--){
        int fst, snd;
        cin>>fst>>snd;
        if(ans[fst-1] == '*')
            ans[fst-1] = snd+'0';
        else if(ans[fst-1] == (snd + '0'))
            continue;
        else{
            // cout<<ans;
            cout<<-1;
            return ;
        }
    }
    if(ans[0] == '*')
        ans[0] = ((n==1)? '0':'1');
    for(int i = 0; i < n; i++)
        if(ans[i] == '*')
            ans[i] = '0';
    if(ans[0] == '0' && n != 1)
        cout<<"-1";
    else
        cout<<ans;
}
int main(){ 
        hs;
        ll t;
        t=1;
        // cin>>t;
        for (int i=1; i<=t; i++){
                //cout<<"Case #"<<i<<": ";
                solve();
         }
        return 0; 
}