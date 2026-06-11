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
    int n, k;
    cin>>n>>k;
    set<int> s;
    for(int i = 1; i <= n; i++)
        s.insert(i);
    while(k--){
        int p;
        cin>>p;
        while(p--){
            int x;
            cin>>x;
            s.erase(x);
        }
    }
    cout<<s.size();
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