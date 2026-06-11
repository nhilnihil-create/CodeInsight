#include<iostream>
#include<vector>

using namespace std;

const long long MOD = 1000000007;
long long cnt[2004][2004];
long long sum[2004][2004];
int same[2004][2004];

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> s(n);
    vector<int> t(m);
    for(int i=0;i<n;i++) cin>>s[i];
    for(int i=0;i<m;i++) cin>>t[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) {
            if (s[i] == t[j]) same[i][j] = 1;
            else same[i][j] = 0;
        }
    }
    for(int i=0;i<=n;i++) cnt[i][0] = 0LL;
    for(int j=0;j<=m;j++) cnt[0][j] = 0LL;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i] != t[j]) {
                cnt[i+1][j+1] = 0LL;
            } else {
                cnt[i+1][j+1] = (sum[i][j] + 1LL) % MOD;
            }
            sum[i+1][j+1] = (sum[i][j+1] + sum[i+1][j] - sum[i][j] + cnt[i+1][j+1] + MOD + MOD) % MOD;
        }
    }
    cout<<(sum[n][m]+1LL)%MOD<<endl;
    return 0;
}
