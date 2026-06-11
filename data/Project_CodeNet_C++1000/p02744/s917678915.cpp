#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<bitset>
#include<deque>
#include<functional>
#include<iterator>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define a first
#define b second
#define sz(x) (ll)((x).size())
#define pb push_back
#define mp make_pair
#define bg begin()
#define ed end()
#define all(x) (x).bg,(x).ed
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep1(i,n) for(ll i=1;i<=(n);i++)
#define rrep(i,n) for(ll i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(ll i=(n);i>=1;i--)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
const ll MOD=1000000007;
const ll INF=1000000000000000;

ll N;
vector<ll> mem(11,0);
void rec(ll rem,ll now){
    if(rem==0){
        rep1(i,N){
            cout<<(char)('a'-1+mem[i]);
        }
        cout<<endl;
    }
    else{
        rep1(i,now){
            mem[N+1-rem]=i;
            rec(rem-1,max(now,i+1));
        }
    }
}

int main(){
    cin>>N;
    ll now=1;
    rec(N,1);
}
