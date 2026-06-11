#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()


int main(){
    string s;
    cin>>s;

    int n=s.size();
    vector<int> ans(n,1);

    rep(i,n-1){
        if(s[i]=='R' && s[i+1]=='R'){
            ans[i+2]+=ans[i];
            ans[i]=0;
        }
    }

    for(int i=n-1;i>0;i--){
        if(s[i]=='L' && s[i-1]=='L'){
            ans[i-2]+=ans[i];
            ans[i]=0;
        }
    }
    rep(i,n) cout<<ans[i]<<" ";
    cout<<endl;

}
