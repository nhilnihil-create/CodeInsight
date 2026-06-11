#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
using vch=vector<char>;
using vvch=vector<vector<char>>;
using vbo=vector<bool>;
using vvbo=vector<vector<bool>>;
using vpii=vector<pair<int,int>>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const int inf=1e9+7;
const ll INF=1e18;

int main(){
    int n,t;cin>>n>>t;
    vin a(n),b(n);
    rep(i,n)cin>>a[i]>>b[i];
    vvin dpa(n+1,vin(t+1)),dpb(n+1,vin(t+1));//dpaは最後の料理を時間をはみ出して食べるときのmax dpbは時間j以内に食べ終わるという条件下でのmax
    rep(i,n)rep2(j,1,t+1){
        dpb[i+1][j]=dpb[i][j];
        if(j>=a[i])dpb[i+1][j]=max(dpb[i+1][j],dpb[i][j-a[i]]+b[i]);
        dpa[i+1][j]=max(dpa[i][j],dpb[i+1][j]);
        //i+1番目の料理を最初と最後どっちにするかで場合分け
        if(j>=a[i])dpa[i+1][j]=max(dpa[i+1][j],dpa[i][j-a[i]]+b[i]);
        dpa[i+1][j]=max(dpa[i+1][j],dpb[i][j-1]+b[i]);
    }
    cout<<dpa[n][t]<<endl;
}