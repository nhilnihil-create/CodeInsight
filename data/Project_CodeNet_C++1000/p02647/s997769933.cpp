#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    int n,K; cin>>n>>K;
    vector<int> p(n),q(n,0);
    rep(i,n) cin>>p[i];
    rep(i,min(K,50)){
        rep(j,n){
            int a=max(0,j-p[j]), b=min(n-1,j+p[j]);
            //cout<<a<<" "<<b<<endl;
            q[a]++;
            if(b!=n-1) q[b+1]--;
        }
        rep(j,n-1) q[j+1]=q[j+1]+q[j];
        p=q;
        q=vector<int>(n,0);
    }
    rep(i,n) cout<<p[i]<<" ";
    cout<<endl;
    return 0;
}