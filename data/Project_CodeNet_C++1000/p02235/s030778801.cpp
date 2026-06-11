#include<string>
int lcs(std::string s, std::string t) {
    const int M = s.size(), N = t.size();
    int dp[M+1][N+1] = {};
    for(int i=0; i<M; ++i)
        for(int j=0; j<N; ++j)
            if(s[i] == t[j]) dp[i+1][j+1] = dp[i][j] + 1;
            else dp[i+1][j+1] = std::max(dp[i+1][j], dp[i][j+1]);
    return dp[M][N];
}
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        string s,t;
        cin>>s>>t;
        cout<<lcs(s,t)<<endl;
    }
}