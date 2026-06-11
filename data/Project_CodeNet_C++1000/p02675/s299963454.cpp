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
    ll n;
    cin>>n;
    int p = n%10;
    vector<int> fst = {2,4,5,7,9}, snd = {0,1,6,8};
    if(find(fst.begin(), fst.end(), p) != fst.end())
        cout<<"hon";
    else if(find(snd.begin(), snd.end(), p) != snd.end())
        cout<<"pon";
    else
        cout<<"bon";
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