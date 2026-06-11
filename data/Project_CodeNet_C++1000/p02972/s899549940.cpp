#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()


int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n) cin>>a[i];

    vector<int> ans;
    vector<bool> b(n+1,false);
    for(int i=n;i>=1;i--){
        int sm=0;
        for(int j=i;j<=n;j+=i){
            if(b[j]) sm++;
        }

        if(a[i-1]==1 && sm%2==0){
            b[i]=true;
            ans.push_back(i);
        }
        else if(a[i-1]==0 && sm%2==1){
            b[i]=true;
            ans.push_back(i);
        }
    }

    cout<<ans.size()<<endl;
    if(ans.size()==0) return 0;
    rep(i,ans.size()){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
