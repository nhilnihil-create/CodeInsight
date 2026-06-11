#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;
#define MOD 1000000007

int main(){
    int r,c;
    cin >> r >> c;
    vector<string> field(r);
    rep(i,r) cin >> field[i];
    vector<vi> r_count(r,vi(c));
    vector<vi> c_count(r,vi(c));
    
    int cnt=1;
    rep(i,r){
        rep(j,c){
            if(field[i][j]=='#'){
                cnt=0;
                r_count[i][j]=cnt;
                cnt++;
            }else{
                r_count[i][j]=cnt;
                cnt++;
            }
        }
        cnt=1;
    }

    rep(i,r){
        for(int j=c-2;j>=0;j--){
            if(field[i][j]=='#') continue;
            r_count[i][j]=max(r_count[i][j],r_count[i][j+1]);
        }
    }

    rep(i,c){
        rep(j,r){
            if(field[j][i]=='#'){
                cnt=0;
                c_count[j][i]=cnt;
                cnt++;
            }else{
                c_count[j][i]=cnt;
                cnt++;
            }
        }
        cnt=1;
    }

    rep(i,c){
        for(int j=r-2;j>=0;j--){
            if(field[j][i]=='#') continue;
            c_count[j][i]=max(c_count[j][i],c_count[j+1][i]);
        }
    }

    int ans=0;
    rep(i,r) rep(j,c) ans=max(ans,r_count[i][j]+c_count[i][j]-1);
    cout << ans << endl;

}