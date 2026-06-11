#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
typedef long long ll;
typedef pair<int,int> pii;

vector<ll> divisor(ll n){
    vector<ll> D;
    D.push_back(n);
    for(int i=2;i*i<n+1;i++){
        if(n%i==0){
            D.push_back(i);
            D.push_back(n/i);
        }
    }
    sort(D.begin(),D.end());
    return D;
}

int main(){
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    ll sum=0;
    rep(i,n) {
        cin>>a[i];
        sum+=a[i];
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());

    /** sumの約数の列挙 **/
    vector<ll> div = divisor(sum);

    vector<ll> b(n),lsum(n+2,0),rsum(n+2,0);
    ll ans  = 1;
    for(auto d: div){
        rep(i,n){
            b[i]=a[i]%d;
        }
        sort(b.begin(),b.end());

        REP(i,n){
            lsum[i]=lsum[i-1]+b[i-1];
            rsum[n-i+1] =d-b[n-i]+rsum[n-i+2];
        }
        ll tk=1e15;
        REP(i,n){
            if(lsum[i]==rsum[i+1]){
                    tk=lsum[i];
                    break;
            }
        }
        if(tk<=k)  ans=max(ans,d);
    }
    cout<<ans<<endl;
    return 0;    
}