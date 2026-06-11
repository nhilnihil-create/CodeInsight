//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    vector<vector<int>> a(3,vector<int>(3,0)),c(3,vector<int>(3,0));
    rep(i,3)rep(j,3) cin>>a[i][j];
    int n; cin>>n;
    rep(i,n){
        int b; cin>>b;
        rep(j,3)rep(k,3){
            if(a[j][k]==b) c[j][k]=1;
        }
    }
    rep(i,3){
        int cnt=0;
        rep(j,3) cnt+=c[i][j];
        if(cnt==3){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    rep(i,3){
        int cnt=0;
        rep(j,3) cnt+=c[j][i];
        if(cnt==3){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    int cnt=0;
    rep(i,3) cnt+=c[i][i];
    if(cnt==3){
        cout<<"Yes"<<endl;
        return 0;
    }
    cnt=0;
    rep(i,3) cnt+=c[i][2-i];
    if(cnt==3){
        cout<<"Yes"<<endl;
        return 0;
    }
    cout<<"No"<<endl;
}
