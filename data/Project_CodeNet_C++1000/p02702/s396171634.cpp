#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;
#define For(i,n,k) for(int i=(n);i<(k);i++)
#define ALL(a)  (a).begin(),(a).end()
ll ans=0;
vector<vector<int>> dp(2,vector<int> (2020,0));
const int m = 2019;
int S;
void Main(){
    string s;cin>>s;
    int n=s.size();
    For(i,0,n){
        S=s[i]-'0';
        ans+=dp[i%2][0];
        For(j,0,m){
            dp[(i+1)%2][(j*10+S)%m]=dp[i%2][j];
        }
        dp[(i+1)%2][S]+=1;
    }
    ans+=dp[n%2][0];
    cout<<ans<<endl;
}
int main(){
    Main();
    /*
    東方風神録は神が出てくるので当然神ゲー
    */
    return 0;
}
