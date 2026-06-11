#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1001001001;
const long long MOD = 1000000007;
const double EPS = 1e-10;

bool solve(){
    int h;
    cin>>h;
    if(h==0)return true;
    int grid[h+1][5]={};
    for(int i=0;i<h;i++){
        for(int j=0;j<5;j++){
            cin>>grid[i+1][j];
        }
    }
    int ans=0;
    bool update=true;
    while(update){
        int fall[h+1][5]={};
        update=false;
        for(int i=1;i<=h;i++){
            int left=17320508,right=-141421356;
            for(int le=0;le<5;le++){
                int val=grid[i][le];
                for(int ri=le+2;ri<5;ri++){
                    bool flag=true;
                    for(int j=le;j<=ri;j++){
                        if(val!=grid[i][j]||grid[i][j]==0)flag=false;
                    }
                    if(flag){
                        left=min(left,le);
                        right=max(right,ri);
                    }
                }
            }
            for(int k=left;k<=right;k++){
                ans+=grid[i][k];
                grid[i][k]=0;
                for(int j=i-1;j>=0;j--)fall[j][k]++;
            }
        }
        for(int i=h;i>=0;i--){
            for(int j=0;j<5;j++){
                if(fall[i][j]>0){
                    update=true;
                    grid[i+fall[i][j]][j]=grid[i][j];
                    grid[i][j]=0;
                    fall[i][j]=0;
                }
            }
        }
    }
    cout<<ans<<endl;
    return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    while(!solve());
}
