#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=998244353;
int main(){
    ll n;cin>>n;
    ll s=1;
    while(s*2<n){
        s*=2;
    }
    rep(i,n){
        REP(j,i+1,n){
            ll k=s;
            ll cnt=1;
            while(i/k==j/k){
                k/=2;
                cnt++;
            }
            cout<<cnt<<' ';
        }
        cout<<endl;
    }
}