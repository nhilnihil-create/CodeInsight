#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define FORC(i,a,b,c) for(ll i=(a);i<(b);i+=(c))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ff first
#define ss second
#define dd long double
#define mod 1000000007

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    string ans;
    while(n){
        ll temp=n%26;
        if(temp==0){
            ans+="z";
            n--;
            n/=26;
            continue;
        }
        ans+=char(temp+96);
        n/=26;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}
