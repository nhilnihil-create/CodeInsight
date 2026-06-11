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

    vector<bool> v(n,false);
    int ans=0;
    for(int i=n;i>=1;i--){
        int cnt=0;
        for(int j=2*i;j<=n;j+=i){
            if(v[j-1]) cnt++;
        }
        if(a[i-1]==1 && cnt%2==0){
            ans++;
            v[i-1]=true;
        }
        else if(a[i-1]==0 && cnt%2==1){
            ans++;
            v[i-1]=true;
        }
    }

    cout<<ans<<endl;
    if(ans==0) return 0;
    rep(i,n){
        if(v[i]) cout<<i+1<<" ";
    }
    cout<<endl;
}

