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



const int modn=1000000007;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> broken(n+1);
    rep(i,m){
        int a;
        cin>>a;
        broken[a]=1;
    }
    vector<ll> dp(n+1);
    for(int i=0;i<=n;++i){
        if(!broken[i]){
            if(i==0)dp[i]=1;
            else if(i==1)dp[i]=1;
            else dp[i]=(dp[i-1]+dp[i-2])%modn;
        }else{
            dp[i]=0;
        }
    }
    cout<<dp[n]<<endl;
}