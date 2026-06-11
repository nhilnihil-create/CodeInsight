//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
using in = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl
const double PI=3.14159265358979323846;
const in MOD = 1000000007;
const in INF=1e18+7;
const int inf=1e9+7;
using P=pair<int,int>;
vector<int> dx={0,1,-1,0};
vector<int> dy={1,0,0,-1};


int main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cout << fixed << setprecision(10);
    string s;
    cin>>s;
    int n=s.size();
    vector<vector<in>> dp(n+1,vector<in>(13,0));
    dp[0][0]=1;
    int ten_cnt=1;
    rep(i,n){
        if(s[n-i-1]=='?'){
            rep(j,10){
                rep(k,13){
                    dp[i+1][(k+j*ten_cnt)%13] += dp[i][k];
                    dp[i+1][(k+j*ten_cnt)%13] %= MOD;
                }
            }
        }

        else{
            int now=s[n-i-1]-'0';
            rep(j,13){
                dp[i+1][(j+now*ten_cnt)%13] = dp[i][j];
            }
        }

        ten_cnt *= 10;
        ten_cnt %= 13;
    }
    cout<<dp[n][5]<<endl;
}/*
./problem.exe
*/