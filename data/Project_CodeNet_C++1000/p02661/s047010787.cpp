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
    int n;
    cin>>n;
    vector<ll> fst(n), snd(n);
    for(int i = 0; i < n; i++)
        cin>>fst[i]>>snd[i];
    double fstmedian, sndmedian;
    sort(fst.begin(), fst.end());
    sort(snd.begin(), snd.end());
    ll ans;
    if(n&1){
        fstmedian = fst[n/2];
        sndmedian = snd[n/2];
        ans = sndmedian - fstmedian + 1;
    }
    else{
        fstmedian = (fst[n/2-1] + fst[n/2])/2.00;
        sndmedian = (snd[n/2 -1] + snd[n/2])/2.00;
        ans = 2*(sndmedian - fstmedian) + 1;
    }
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