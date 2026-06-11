#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()

int main(){
    int N;cin>>N;
    vector<int>W(N);
    rep(i,N)cin>>W.at(i);
    int sum1=0,sum2=0;
    int ans=10000000;
    rep(i,N-1){
        for(int j=0;j<=i;j++){
            sum1+=W.at(j);
        }
        for(int j=i+1;j<N;j++){
            sum2+=W.at(j);
        }
        if(abs(sum2-sum1)<ans){
            ans=abs(sum2-sum1);
        }
        sum1=0;
        sum2=0;
    }
    cout<<ans<<endl;
}