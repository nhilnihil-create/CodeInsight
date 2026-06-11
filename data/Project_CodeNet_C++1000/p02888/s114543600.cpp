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
    vector<int> L(n);
    rep(i,n) cin>>L[i];

    sort(all(L));
    ll ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int k=lower_bound(all(L),L[i]+L[j])-L.begin();
            ans+=max(k-(j+1),0);
        }
    }

    cout<<ans<<endl;
}

