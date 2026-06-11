#include <bits/stdc++.h> 
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<int>>;

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}

int main(){
    ll l,r;
    cin>>l>>r;
    ll q=r-l+1;
    if(q>=2019){
        cout<<0<<endl;
        return 0;
    }else{
        int ans=2019;
        for(ll i=l;i<=r;++i){
            for(ll j=i+1;j<=r;++j){
                int temp=(i*j)%2019;
                ans=min(ans,temp);
            }
        }
        cout<<ans<<endl;
        return 0;
    }
}
