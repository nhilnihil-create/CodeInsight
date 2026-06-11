#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int ans=0;
    int cnt=1;
    rep(i,n-1){
        if(s[i]!=s[i+1]){
            ans+=cnt-1;
            cnt=1;
        } 
        else cnt++;
    }
    ans+=cnt-1;

    cout<<min(n-1,ans+k*2)<<endl;
}
