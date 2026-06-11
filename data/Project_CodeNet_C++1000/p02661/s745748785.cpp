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
    ll start[n];
    ll endd[n];
    REP(i,n){
        cin>>start[i]>>endd[i];
    }
    sort(start,start+n);
    sort(endd,endd+n);
    if(n & 1){
        ll med1=start[n/2];
        ll med2=endd[n/2];
        cout<<med2-med1+1<<endl;

    }
    else{
        ll med1=start[n/2-1]+start[n/2];
        ll med2=endd[n/2-1]+endd[n/2];
        cout<<med2-med1+1<<endl;
    }
}
