#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a)  (a).begin(),(a).end()
#define pb push_back
#define INF 99999999

#define MAX_S 2000
#define MAX_T 2000

template<typename T> int lcs(T s,T t){
    int lens=s.size();
    int lent=t.size();
    int dp[MAX_S+1][MAX_T+1]={};

    rep(i,lens){
        rep(j,lent){
            if(s[i]==t[j])  dp[i+1][j+1] = dp[i][j]+1;
            else            dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
        }
    }
    return dp[lens][lent];
}

int main(){
    int n;
    cin>>n;
    rep(i,n){
        string s,t;
        cin>>s>>t;
        cout<<lcs(s,t)<<endl;
    }
}