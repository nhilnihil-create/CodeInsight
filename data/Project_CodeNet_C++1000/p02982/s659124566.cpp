#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int n,d;cin>>n>>d;
    int x[n][d];
    
    rep(i,n)rep(j,d)cin>>x[i][j];
    
    int ans = 0;
    rep(i,n)rep(j,i){
        int tmp = 0;
        rep(k,d)tmp+=(x[i][k]-x[j][k])*(x[i][k]-x[j][k]);
        
        int tmp2 = tmp;
        tmp2 = sqrt(tmp2);
        tmp2*=tmp2;
        if(tmp==tmp2)++ans;
    }
    cout<<ans<<endl;
	return 0;
}