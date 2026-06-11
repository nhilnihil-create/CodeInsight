#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define RREP(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//const ll INF = 1LL << 60;
//const int INF = 1001001001;

int main(void){
    int n,k;
    cin >> n >> k;
    vector<int> a(3);
    REP(i,3) cin >> a[i];
    string s;
    cin >> s;
    vector<int> ctoi(256);
    ctoi['r']=2;
    ctoi['c']=0;
    ctoi['p']=1;
    int ans=0;
    REP(i,k){
        vector<int> x;
        for(int j=i;j<n;j+=k){
            x.push_back(ctoi[s[j]]);
        }
        vector<int> dp(2);
        int pre=-1;
        for(int nx :x){
            vector<int> p(2);
            swap(dp,p);
            dp[0]=max(p[0],p[1]);
            if(pre==nx){
                dp[1]=p[0]+a[nx];
            }else{
                dp[1]=max(p[0],p[1])+a[nx];
            }
            pre=nx;
        }
        ans+=max(dp[0],dp[1]);
    }
    cout << ans << endl;
    return 0;
}