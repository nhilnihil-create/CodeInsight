#include <bits/stdc++.h>
#define rep(i,a) for(int i=0;i<int(a);++i)
#define REP(i,a,b) for(int i=int(a);i<int(b);++i)
#define pb push_back
#define mp make_pair
#define F first
#define S second
using ll = long long;
using itn = int;
using namespace std;
using Graph = vector<vector<int>>;
static const long double GRATIO=(long double)(1+sqrt(5))/2;
ll GCD(ll a, ll b){
    return b ? GCD(b, a%b) : a;
}
ll LCM(ll a, ll b){
    return a/GCD(a,b)*b;
}
int main(){
    int N;
    cin>>N;
    pair<int,int> xy[N];
    rep(i,N) cin>>xy[i].first>>xy[i].second;
    sort(xy,xy+N);
    map<pair<int,int>,int> sa;
    rep(i,N){
        for(int j=0; j<i; j++){
            sa[mp(xy[i].first-xy[j].first,xy[i].second-xy[j].second)]++;
        }
    }
    int cnt=0;
    for(auto i:sa){
        cnt=max(cnt,i.second);
    }
    cout<<N-cnt<<endl;
}
