#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>
#include<cmath>
#include<numeric>
#include<queue>
#include<stack>
#include<cstring>
#include<limits>
#include<functional>
#include<unordered_set>
#include<iomanip>
#include<cassert>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define pb push_back
#define eb emplace_back
using ll=long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 50;
 
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
using namespace std;

void solve(){
    ll t1,t2;
    cin>>t1>>t2;
    ll a1,a2,b1,b2;
    cin>>a1>>a2;
    cin>>b1>>b2;
    ll sub,cnt=0;
    if(a1!=b1&&(a1*t1+a2*t2==b1*t1+b2*t2)){
        cout<<"infinity\n";
        return;
    }
    else if(a1>b1){
        if(a1*t1+a2*t2<b1*t1+b2*t2){
            sub=(b1-a1)*t1+(b2-a2)*t2;
            ll x=(a1-b1)*t1/sub;
            cnt=2*x;
            if((b1-a1)*t1%sub)++cnt;
        }
    }
    else if(a1<b1){
        if(a1*t1+a2*t2>b1*t1+b2*t2){
            sub=(a1-b1)*t1+(a2-b2)*t2;
            ll x=(b1-a1)*t1/sub;
            cnt=2*x;
            if((b1-a1)*t1%sub)++cnt;
          
        }
    }
    cout<<cnt<<endl;
}
 
int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
	cout<<fixed<<setprecision(15);
	solve();
	return 0;
}
