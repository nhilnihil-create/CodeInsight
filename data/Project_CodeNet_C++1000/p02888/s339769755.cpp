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
    rep(i,n){
        for(int j=i+1;j<n;j++){
            int a=L[i];
            int b=L[j];
            int r=lower_bound(all(L),a+b)-L.begin();
            r--;
            int l=upper_bound(all(L),abs(a-b))-L.begin();
            ans+=r-l+1;
            //cout<<a<<" "<<b<<" "<<l<<" "<<r<<endl;
            if(l<=i && i<=r) ans--;
            if(l<=j && j<=r) ans--;
        }
    }

    cout<<ans/3<<endl;
}
