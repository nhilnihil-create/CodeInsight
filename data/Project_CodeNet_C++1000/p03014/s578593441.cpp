#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
typedef long long ll;
typedef pair<int,int> pii;

int field[2005][2005];
int hcos[2005][2005];
int wcos[2005][2005];
int main(){
    int h,w;
    cin>>h>>w;
    REP(i,h){
        string s;
        cin>>s;
        REP(j,w){
            if(s[j-1]=='.'){
                field[i][j]=0;
            }else{
                field[i][j]=1;
            }
        }
    }

    REP(i,h){
        int cnt=0;
        REP(j,w){
            if(field[i][j]==1){
                cnt = 0;
                hcos[i][j]=0;
            }else{
                cnt++;
                hcos[i][j]=cnt;
            }
        }
        for(int j=w-1;j>0;j--){
            if(hcos[i][j]==0) continue;
            if(hcos[i][j]<hcos[i][j+1]){
                hcos[i][j]=hcos[i][j+1];
            }
        }
    }

    REP(j,w){
        int cnt=0;
        REP(i,h){
            if(field[i][j]==1){
                cnt = 0;
                wcos[i][j]=0;
            }else{
                cnt++;
                wcos[i][j]=cnt;
            }
        }
        for(int i=h-1;i>0;i--){
            if(wcos[i][j]==0) continue;
            if(wcos[i][j]<wcos[i+1][j]){
                wcos[i][j]=wcos[i+1][j];
            }
        }
    }
    int ans = 0;
    REP(i,h){
        REP(j,w){
            if(field[i][j]==1) continue;
            ans = max(ans,wcos[i][j]+hcos[i][j]-1);
        }
    }

    cout<<ans<<endl;
    return 0;
}