#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout<< (x) << " "

int main(){
    int A,B,M;cin>>A>>B>>M;
    int amin=100000,bmin=100000;
    vector<int> a(A),b(B),c(M);
    rep(i,A){cin>>a[i];amin=min(amin,a[i]);}
    rep(i,B){cin>>b[i];bmin=min(bmin,b[i]);}
    int ans = amin+bmin;
    rep(i,M){
        int x,y,c;cin>>x>>y>>c;
        ans = min(ans, a[x-1]+b[y-1]-c);
    }
    co(ans);
}