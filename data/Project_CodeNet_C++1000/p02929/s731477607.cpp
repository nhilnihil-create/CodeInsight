#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
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
const ll inf=1e9+7;
const ll mod=998244353;
int main(){
    ll n;cin>>n;
    string s;cin>>s;
    ll cnt=0;
    ll ans=1;
    ll a=0,b=0;
    rep(i,n*2){
        if(s[i]=='B'){
            if(cnt%2==0){
                cnt++;
                a++;
            }
            else{
                ans*=cnt;
                ans%=inf;
                cnt--;
                b++;
            }
        }else{
            if(cnt%2==0){
                ans*=cnt;
                ans%=inf;
                cnt--;
                b++;
            }else{
                cnt++;
                a++;
            }
        }
    }
    rep(i,n){
        ans*=i+1;
        ans%=inf;
    }
    if(a!=b)ans=0;
    cout<<ans<<endl;
}