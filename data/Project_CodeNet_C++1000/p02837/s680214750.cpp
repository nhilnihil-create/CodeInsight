#include <bits/stdc++.h>

using namespace std;
using namespace std;
#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
//rep…「0からn-1まで」の繰り返し
#define rep2(i,s,n) for(long long i=s; i<=(long long)(n);i++)
//rep2…「sからnまで」の繰り返し
#define repr(i,s,n) for(long long i=s;i>=(long long)(n);i--)
//repr…「ｓからnまで」の降順の繰り返し

typedef long long ll;

const ll inf = 1e9+7;
const ll mod = 1e9+7;

int main(){
    int n;
    cin>>n;

    vector<vector<int>>xy(n,vector<int>(15,-1));

    rep(i,n){
        int a;
        cin>>a;

        rep(j,a){
            int x,y;
            cin>>x>>y;

            x--;

            xy[i][x]=y;
        }
    }

    int ans=0;

    rep(bit,1<<n){
        bool jdg=true;
        int cnt=0;

        rep(i,n){
            if(bit&(1<<i)){
                cnt++;
                rep(j,xy[i].size()){
                    if(xy[i][j]==1){
                        if(!(bit&(1<<j))){
                            jdg=false;
                        }
                    }
                    else if(xy[i][j]==0){
                        if(bit&(1<<j)){
                            jdg=false;
                        }
                    }
                }
            }
        }

        if(jdg)ans=max(ans,cnt);
    }
    cout<<ans<<endl;

}
