#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);


int main(void)
{
    ll n,cnt=0;
    cin>>n;
    queue<pair<string,ll>> q;
    rep(i,n){
        string s;
        ll t;
        cin>>s>>t;
        q.push({s,t});
    }
    string x;
    cin>>x;
    while(!q.empty()){
        pair<string,ll> a=q.front();
        if(a.first!=x) q.pop();
        else{
            q.pop();
            break;
        }
    }
    while(!q.empty()){
        pair<string,ll> p=q.front();
        cnt+=p.second;
        q.pop();
    }
    cout<<cnt<<endl;
    return 0;
}