#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pll pair<long long, long long>
#define f first
#define s second
#define debug cout<<"here\n" 
#define MOD 1000000009

const int MAXN = 2e5 +15;
 
using namespace std;

void solve(){    
    ll x,k,d; cin>>x>>k>>d;
    x = abs(x);
    if(k < (x/d)) cout<<x-k*d;
    else{
        k -= (x/d);
        x -= (x/d)*d;
        if(k%2) cout<<d-x;
        else cout<<x;
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);    
    cout<<fixed<<setprecision(12);

    int t =1; //cin>>t;
    for(int i=1; i<= t; i++){
        solve();
        cout<<"\n";
    }
    
    return 0;
}   