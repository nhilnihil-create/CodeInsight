// Hail god Yato
 
#include <bits/stdc++.h> 
using namespace std;
 
#define hs ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll mod = 1000000007;
const ll INF = 1e18;
const ll MAX = 100001;
//
//
void solve(){
    string str;
    cin>>str;
    vector<int> ans(3, 0);
    ans[0] = str[0]=='R';
    for(int i = 1; i < 3; i++){
        ans[i] = ans[i-1];
        if(str[i] == 'R')
            ++ans[i];
        else
            ans[i] = 0;
    }
    cout<<max(ans[0], max(ans[1], ans[2]));
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