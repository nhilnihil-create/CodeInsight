#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<=(n);i++)
#define rep3(i,i0,n) for(int i=i0;i<(n);i++)
#define pb push_back
#define mod 1000000007
#define INF 2000000000
typedef long long ll;
bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first){
        return a.first < b.first;
        
    }else{
        return a.second < b.second;
    }
}
// 入力



int main() {
    
    ll H,W,K;
    
    cin >>H>>W>>K;

    vector<vector<char>> c(H,vector<char>(W));
    ll olg=0;
    ll ans = 0;
    rep(i,H){
        rep(j,W){
            cin>>c[i][j];
            if(c[i][j] == '#'){
                olg++;
            }
        }
    }

    ll n = H+W;
    ll now = olg;
    vector<vector<char>> c2(H,vector<char>(W));
    c2 = c;
    rep(i,(1<<n)){
        c = c2;
        vector<ll> S;
        rep(j,n){
            if(i&(1<<j)){
                S.pb(j);
            }
        }
        now = olg; 
        rep(j,S.size()){
            if(S[j]<H){
                rep(k,W){
                    if(c[S[j]][k] == '#'){
                        now--;
                        c[S[j]][k] = 'r';
                    }
                }
            }else{
                rep(k,H){
                    if(c[k][S[j]-H] == '#'){
                        now--;
                        c[k][S[j]-H] = 'r';
                    }
                }
            }
        }
   
        if(now == K){
            ans++;
        }
       
        
    }
  
    

    cout<<ans<<endl;
    
    
    return 0;
    

}