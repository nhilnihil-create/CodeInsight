#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;

int a[15][15];

int main()
{
    int ans=0;
    //入力
    int n;
    cin>>n;
    rep(i,n) rep(j,n) a[i][j]=-1;   //a[i][j] = iの、kに対する証言
    rep(i,n){
        int num;
        cin>>num;
        rep(j,num){
            int x,y;
            cin>>x>>y;
            x--;
            a[i][x]=y;
        }
    }
    
    //bit全探索
    rep(i,1<<n){
        //正直者は誰か？
        vector<int> d(n);
        rep(j,n){
            if(i>>j&1){
                d[j]=1;
            }
        }
        //正直者なら、証言を照らし合わせる
        bool hantei=true;
        rep(j,n){
            if(d[j]){
                rep(k,n){
                    if(a[j][k]==-1) continue; //証言していないなら、continue;
                    if(a[j][k]!=d[k]){
                        hantei=false;
                        break;
                    }
                }
            }
        }
        if(hantei) ans=max(ans,__builtin_popcount(i));
    }
    cout<<ans;
}