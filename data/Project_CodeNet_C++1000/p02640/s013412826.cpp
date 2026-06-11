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
    ll x,y;
    cin>>x>>y;
    if(y & 1){
        cout<<"No"<<endl;
        return 0;
    }
    y/=2;
    if(y>=x && y-x<=x){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}
