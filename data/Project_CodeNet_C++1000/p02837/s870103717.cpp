#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n;cin>>n;
    vector<vector<int>> t(n,vector<int>(n,-1));
    rep(i,n){
        int a;cin>>a;
        rep(j,a){
            int x,y;cin>>x>>y;x--;
            t[i][x]=y;
        }
    }
    int res=0;
    for(int i=0;i<(1<<n);i++){
        bool jud=true;
        rep(j,n){
            if((i&(1<<j))==0)continue;
            rep(k,n){
                if(t[j][k]==0&&(i&(1<<k))!=0){
                    jud=false;
                    break;
                }else if(t[j][k]==1&&(i&(1<<k))==0){
                    jud=false;
                    break;
                }
            }
        }
        int buf=0;
        rep(j,n)if(i&(1<<j))buf++;
        if(jud){
            //cout<<i<<endl;
            chmax(res,buf);
        }
    }
    cout<<res<<endl;
}