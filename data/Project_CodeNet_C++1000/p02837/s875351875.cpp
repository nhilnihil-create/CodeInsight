#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define pb(a) push_back(a)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;
using P  = pair<int,int>;
using vP = vector<P>;

int main(){
    int n; cin>>n;
    vv sh(n, vi (n,-1));//証言なし: -1
    
    int a,x,y;
    
    rep(i,n){
        cin>>a;
        rep(j,a){
            cin>>x>>y;
            x--;
            sh[i][x] = y;//正直: 1, 不定: 0
        }
    }
    
    int ans = 0, count;
    
    rep(i, 1<<n){
        
        count = 0;
        bool ok = true;
        
        rep(j,n){
            if(!(i&1<<j))continue;
            count++;
            
            rep(k, sh[j].size()){
                if((i&1<<k) && sh[j][k]==0){
                    ok = false;
                    break;
                }else if(!(i&1<<k) && sh[j][k]==1){
                    ok = false;
                    break;
                }
            }
            
            if(!ok)break;
        }
        
        if(ok)ans = max(ans, count);
    }
    
    
    cout << ans << endl;
    
    return 0;
}