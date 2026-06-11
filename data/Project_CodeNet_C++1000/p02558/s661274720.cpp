#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define REP(i, n) for(int i = 0;i < (n);i++)
#define lint long long
const lint mod=1e9+7;
const lint inf=2.19e15+1;
const long double eps=1e-10;
template <class T,class U>bool chmin(T& a,U b){if(a>b){a=b;return true;}return false;}
template <class T,class U>bool chmax(T& a,U b){if(a<b){a=b;return true;}return false;}

signed main(){
    int n, q;
    cin >> n >> q;
    dsu uni(n + 1);
    REP(i,q){
        int t, u, v;
        cin >> t >> u >> v;
        if (t==0){
            uni.merge(u, v);
        }
        else{
            if (uni.same(u,v)){
                cout << 1 << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
    }
}