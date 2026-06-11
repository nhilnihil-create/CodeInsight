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
    vector<int> a(n);
    rep(i,n) cin>>a[i];

    int ng=0,ok=1000000001;
    while(ok-ng>1){
        int mid=(ok+ng)/2;
        int cnt=0;
        rep(i,n){
            cnt+=a[i]/mid;
            if(a[i]%mid==0) cnt--;
        }

        if(cnt<=k) ok=mid;
        else ng=mid;
    }

    cout<<ok<<endl;
}