#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
const ll mod = 1000000007;
const ll INF = 1e+14;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define _GLIBCXX_DEBUG

int main(){
    ll N;
    cin>>N;
    vector<ll> a;
    rep(i,N){
        ll v;
        cin>>v;
        a.push_back(v);
    }
    ll s;
    rep(i,50){
        int count=0;
        rep(j,N){
            if(a[j]&(1<<i)) count++;
        }
        if(count%2==1) s|=(1<<i);
    }

    rep(i,N){
        ll count=0;
        rep(j,50){
            if(((s&(1<<j))&&(!(a[i]&(1<<j))))||((!(s&(1<<j)))&&(a[i]&(1<<j)))){
                count|=(1<<j);
            }
        }
    cout<<count<<" ";
    }
    cout<<endl;
}