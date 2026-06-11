#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1000000007;
const ll INF=1e9;
const ll IINF=1e18;
const double EPS=1e-8;
const double pi=acos(-1);

template<class T> inline bool chmin(T &a,T b){
    if (a>b){
        a=b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){
        a=b;
        return true;
    }
    return false;
}

int main(){
    int N;
    cin >> N;
    map<int,int> m;
    rep(i,N){
        int a;
        cin >> a;
        m[a]++;
    }
    vector<int> cnt;
    for (auto x:m){
        cnt.push_back(x.second);
    }
    sort(cnt.begin(),cnt.end());
    int s=cnt.size();
    vector<int> cnt2(s+1);
    cnt2[0]=0;
    rep(i,s){
        cnt2[i+1]=cnt2[i]+cnt[i];
    }
    rep(i,N){
        int lb=-1,ub=N+1;
        while(ub-lb>1){
            int mid=(ub+lb)/2;
            int x=lower_bound(cnt.begin(),cnt.end(),mid)-cnt.begin();
            int sum=cnt2[x]+mid*(s-x);
            if (sum>=(i+1)*mid){
                lb=mid;
            }
            else {
                ub=mid;
            }
        }
        cout << lb << endl;
    }
}