#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define inf LLONG_MAX>>2
#define MAX 1000000
#define mod 2019
#define pb push_back
#define f(i,a,n,x) for ((i)=(a);(i)<(n);(i)+=(x))
#define fd(i,a,n,x) for ((i)=(a);(i)>=(n);(i)-=(x))
#define fi first
#define se second
#define mk make_pair
#define pi pair
#define vt vector
using namespace std;
void read(vt<ll> &a,ll n){ll i,temp;f(i,0,n,1){cin>>temp;a.pb(temp);}}
void solve(){
    string s;
    unordered_map<ll,ll> countsuf;
    ll i,val=0,pot=1,answer=0;
    cin>>s;
    countsuf[val]++;
    fd(i,s.length()-1,0,1){
        val=(val+(s[i]-'0')*pot)%mod;
        pot=(pot*10)%mod;
        answer+=countsuf[val];
        countsuf[val]++;
    }
    cout<<answer<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}