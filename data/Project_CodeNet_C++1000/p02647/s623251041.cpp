#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<ll,ll>
#define PP pair<P,P>
using namespace std;

int main(){
    int n,k; cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    rep(j,k){
        bool check=true;
        vector<int> ans(n,0);
        rep(i,n){
            int l=max(0,i-a[i]);
            int r=min(n-1,i+a[i]);
            ans[l]++;
            if(r<n-1) ans[r+1]--;
        }
        rep(i,n-1) ans[i+1]+=ans[i];
        rep(i,n){
            if(ans[i]!=n){
                check=false;
                break;
            }
        }
        a=ans;
        if(check) break;
    }
    rep(i,n) cout << a[i] << ' ';
    cout << endl;
return 0;
}

