#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

int n,k,w[100001];
bool test(ll d){
    int cnt=1;
    ll sum=0;
    rep(i,n){
        if(sum+w[i]>d){
            ++cnt;
            if(d>=w[i])sum=w[i];
            else return false;
        }
        else sum+=w[i];
    }
    if(cnt<=k) return true;
    else return false;
}
int main(){
    cin>>n>>k;
    rep(i,n) cin>>w[i];
    ll lb=0,ub=1000100010001000;
    while(ub-lb>1){
        ll mid=(lb+ub)/2;
        if(test(mid)) ub=mid;
        else lb=mid;
    }
    cout<<ub<<endl;
    return 0;
}
