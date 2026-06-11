#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll GCD(ll a, ll b){ return a ? GCD(b % a, a) : b; }
int main(){
    int h,w,k;
    cin>>h>>w>>k;
    vector<vector<char>> c(h,vector<char>(w));
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++) cin>>c[i][j];
    }
    int ans = 0;
    for(int i=0; i<(1<<h); i++){
        vector<bool> hf(h,false);
        for(int k=0; k<h; k++){
            hf[k] = i&(1<<k);
        }
        for(int j=0; j<(1<<w); j++){
            vector<bool> wf(w,false);
            for(int l=0; l<w; l++){
                wf[l] = j&(1<<l);
            }
            int cnt = 0;
            for(int ii=0; ii<h; ii++){
                for(int jj=0; jj<w; jj++){
                    if(hf[ii]||wf[jj]) continue;
                    if(c[ii][jj]=='#') cnt++;
                }
            }
            if(cnt==k) ans++;
            //cout<<cnt<<endl;
        }
    }
    cout<<ans<<endl;
    
}