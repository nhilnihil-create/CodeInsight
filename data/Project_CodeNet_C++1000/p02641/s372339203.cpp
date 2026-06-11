#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
const ll mod = 1000000007;
const ll INF = 1e+14;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define _GLIBCXX_DEBUG

int main(){
    int x,n; cin>>x>>n;
    vector<int> p;
    rep(i,n){
        int v; cin>>v;
        p.push_back(v);
    }
    int ans;
    rep(i,100){
        bool judge=false;
        int pla=x+i;
        int mai=x-i;
        rep(j,n){
            if(p[j]==mai){
                judge=true;
                break;
            }
        }
        if(!judge) {
            ans=mai;
            break;
        }
        judge=false;
        rep(j,n){
            if(p[j]==pla){
                judge=true;
                break;
            }
        }
        if(!judge) {
            ans=pla;
            break;
        }
    }
    cout<<ans<<endl;
}