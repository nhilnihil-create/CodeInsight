#include <bits/stdc++.h> 
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
#define MAX 100005
#define NIL -1
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<int>>;

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}

const double PI=(acos(-1));

int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n)cin>>a[i];
    sort(a.rbegin(),a.rend());
    ll ans=a[0];
    for(int i=2;i<n;++i){
        ans+=a[i/2];
    }
    cout<<ans<<endl;

}