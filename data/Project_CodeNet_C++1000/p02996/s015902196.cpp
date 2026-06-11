#include <bits/stdc++.h>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const long long INF = 1LL << 60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    int n;cin>>n;
    vector<int >a(n);
    vector<int>b(n);
    rep(i,n){
        cin>>a[i]>>b[i];
    }
    vector<P>p(n);
    rep(i,n){
        p[i]=make_pair(b[i],a[i]);

    }
    sort(p.begin(),p.end());
    ll sum = 0;
    rep(i,n){
        sum+=p[i].second;
        if(sum>p[i].first){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}