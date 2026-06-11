#include<bits/stdc++.h>
#define INFTY 10000000000
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
const int MOD=1000000007;
const int di[4] = {-1,0,1,0};
const int dj[4] = {0,-1,0,1};
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}

int main(){
    int h,w;cin>>h>>w;
    char s[h][w];
    rep(i,h)rep(j,w)cin>>s[i][j];

    int l[h][w],r[h][w],f[h][w],b[h][w];
    rep(i,h){
        rep(j,w){    
         
        if(s[i][j]=='.'){
            if(j==0) l[i][j] = 1;
            else l[i][j] = l[i][j-1] + 1;
        }
        
        else{
            l[i][j] = 0;
        }
    }
    }
    rep(i,h){
        rep(j,w){     
            if(s[i][j]=='.'){
                if(i==0)f[i][j] = 1;
                else f[i][j] = f[i-1][j]+1;
            }
            else{
                f[i][j] = 0;
            }
        }
    }
    rep(i,h){
            for(int j=w-1;j>=0;j--){     
                if(s[i][j]=='.'){
                    if(j==w-1) r[i][j] = 1;
                    else r[i][j] = r[i][j+1]+1;
                }
                else{
                    r[i][j] = 0;
                }
            }
        }
    for (
        int i = h-1; i >= 0; i--)
    {
        rep(j,w){     
            if(s[i][j]=='.'){
                if(i==h-1) b[i][j] = 1;
                else b[i][j] = b[i+1][j] + 1;
            }
            else{
                b[i][j] = 0;
            }
        }
    }
    int mx=0;
    rep(i,h)rep(j,w){
        int sum;
        sum = r[i][j] + b[i][j] + l[i][j] + f[i][j] -3;
        mx = max(mx,sum);
    }

    cout<<mx<<endl;
    return 0;
}