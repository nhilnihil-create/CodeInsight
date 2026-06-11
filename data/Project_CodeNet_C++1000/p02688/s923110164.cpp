#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int n,k;cin>>n>>k;
    int a[n];
    memset(a,0,sizeof(a));
    
    rep(i,k){
        int d;cin>>d;
        rep(j,d){
            int c;cin>>c;
            --c;
            ++a[c];
        }
    }
    sort(a, a+n);
    int ans = 0;
    rep(i,n){
        if(a[i]==0)++ans;
        else break;
    }
    cout<<ans<<endl;
	return 0;
}