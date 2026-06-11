#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
int mod =1000000007;
const double PI = acos(-1);
int main(){
    int h,w;cin>>h>>w;
    vector<string>s(h);
    rep(i,h)cin>>s[i];
    int ta[h][w],yo[h][w];
    rep(i,h)rep(j,w){
        ta[i][j]=0;
        yo[i][j]=0;
    }
    rep(i,h){
        int cnt =0;
        rep(j,w){
            if(s[i][j]=='.'){
                cnt++;
                yo[i][j]=cnt;
            }
            else{
                cnt=0;
                yo[i][j]=cnt;
            }
        }
        cnt=-1;
        rep(j,w){
            if(cnt==-1&&yo[i][w-j-1]!=0){
                cnt=yo[i][w-1-j];
            }
            else if(yo[i][w-1-j]!=0){
                yo[i][w-1-j]=cnt;
            }
            else {
                cnt=-1;
            }
        }
    }
    rep(j,w){
        int cnt =0;
        rep(i,h){
            if(s[i][j]=='.'){
                cnt++;
                ta[i][j]=cnt;
            }
            else{
                cnt=0;
                ta[i][j]=cnt;
            }
        }
        cnt=-1;
        rep(i,h){
            if(cnt==-1&&ta[h-1-i][j]!=0){
                cnt=ta[h-1-i][j];
            }
            else if(ta[h-1-i][j]!=0){
                ta[h-1-i][j]=cnt;
            }
            else {
                cnt=-1;
            }
        }
    }
    int ans=0;
    rep(i,h)rep(j,w){
        ans=max(ans,ta[i][j]+yo[i][j]-1);
    }
    cout<<ans<<endl;
}