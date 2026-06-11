#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
typedef long long ll;
typedef pair<int,int> pii;

int main(){
    int n;
    cin>>n;
    vector<int> w(n+1);
    vector<int> sum_w(n+1,0);
    REP(i,n){
        cin>>w[i];
        sum_w[i]=sum_w[i-1]+w[i];
    }
    int ans = 1e9+7;
    REP(i,n-1){
        ans = min(abs(sum_w[n]-2*sum_w[i]),ans);
    }
    cout<<ans<<endl;
    return 0;
}