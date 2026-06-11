#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
using namespace std;
const long long int INF = 1e18;
const long long int mod = 1e9+7;

typedef pair<ll, ll> pairs;
typedef vector<pairs> p;

struct Edge{
    ll to, weight;
    Edge(ll t, ll w) : to(t), weight(w){}
};
using graph = vector<vector<ll>>;
using Graph = vector<vector<Edge>>;


ll gcd(ll a,ll b){
    if(b == 0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}

ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

ll keta(ll N){
    int tmp{};
    while( N > 0 ){
        tmp += ( N % 10 );
        N /= 10;
    }
    N = tmp;
    return N;
}

// 回文
bool kai(string S){
    bool flag = true;
    for(ll i=0;i<S.size()/2;++i){
        if(S[i] != S[S.size()-i-1]){
            flag = false;
            break;
        }
    }
    return flag;
}
// ---------------------------------------------

int main(){
    ll h, w, a, b;
    cin>>h>>w>>a>>b;


    for(ll i=0;i<b;++i){
        for(ll j=0;j<a;++j){
            cout<<1;
        }
        for(ll j=a;j<w;++j){
            cout<<0;
        }
        cout<<endl;
    }
    for(ll i=b;i<h;++i){
        for(ll j=0;j<a;++j){
            cout<<0;
        }
        for(ll j=a;j<w;++j){
            cout<<1;
        }
        cout<<endl;
    }
    return 0;
}