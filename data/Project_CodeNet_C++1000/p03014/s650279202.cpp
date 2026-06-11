#include <iostream>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define c_max(a, b) (((ll)a)>((ll)b)?(a):(b))
#define c_min(a,b) (((ll)a)<((ll)b)?(a):(b))
#define chmax(x,a) x=c_max(x,a)
#define chmin(x,a) x=c_min(x,a)
int sum[2010][2010],SUM[2010][2010];
bool s[2010][2010];

int main(){
    int h,w;cin>>h>>w;
    rep(i,h)rep(j,w){
        char t;cin>>t;
        if(t=='.')s[i][j]=1;
        else s[i][j]=0;
        }
    rep(i,h)sum[i][0]=s[i][0];
    rep(i,h)rep(j,w){
        if(s[i][j+1]==0){sum[i][j+1]=0;continue;}
        sum[i][j+1]=sum[i][j]+s[i][j+1];
    }
    rep(i,h)for(int j=1;j<w;j++){
        if(sum[i][w-j-1]&&sum[i][w-j])sum[i][w-j-1]=sum[i][w-j];
    }
    rep(i,w)SUM[0][i]=s[0][i];
    rep(i,w)rep(j,h){
        if(s[j+1][i]==0){SUM[j+1][i]=0;continue;}
        SUM[j+1][i]=SUM[j][i]+s[j+1][i];
    }
    rep(i,w)for(int j=1;j<h;j++){
        if(SUM[h-j-1][i]&&SUM[h-j][i])SUM[h-j-1][i]=SUM[h-j][i];
    }
    ll ans=0;
    rep(i,h)rep(j,w){
        if(s[i][j])chmax(ans,sum[i][j]+SUM[i][j]-1);
    }
    cout<<ans<<endl;

}