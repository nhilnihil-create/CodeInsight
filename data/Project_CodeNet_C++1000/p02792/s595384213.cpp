#include <bits/stdc++.h> 
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
#define MAX 100005
#define NIL -1
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<int>>;
using P =pair<int,int>;

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}

P f(int x){
    int a=x%10;
    int b=0;
    while(x){
        b=x;
        x/=10;
    }
    return P(a,b);
}

int main(){
    int n;
    cin>>n;
    map<P,int> freq;
    for(int i=1;i<=n;++i){
        P p=f(i);
        freq[p]++;
    }
    ll ans=0;
    for(int i=1;i<=n;++i){
        P p=f(i);
        P q(p.second,p.first);
        ans+=freq[q];
    }
    cout<<ans<<endl;
}