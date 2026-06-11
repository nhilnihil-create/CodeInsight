#include <bits/stdc++.h>//Carefully Crafted by hetp111
using namespace std;
//#define int long long
#define double long double
#define all(v) (v).begin(),(v).end()
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define MOD (1000000007)
#define MOD2 (998244353)
#define MOD3 (1000000009)
#define PI acos(-1)
#define eps (1e-8)
#define INF (1e18)
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0)
template<class A,class B>ostream&operator<<(ostream&out,const pair<A,B>&a){return out<<"("<<a.first<<","<<a.second<<")";}
template<class A>ostream&operator<<(ostream&out,const vector<A>&a){for(const A &it:a)out<<it<<" ";return out;}
template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}
ifstream cinn("ride.in");ofstream coutt("ride.out");
int poww(const int &a,int b,const int &m=MOD){if(b==0)return 1;int x=poww(a,b/2,m);x=x*x%m;if(b&1)x=x*a%m;return x;}
int ceil(const int &a,const int &b){return (a+b-1)/b;}
////Read:
//Check corner cases, n==1;
//
////Some function:
//__builtin_popcountll(), 

char v[2000][2000];
int Rnext[2000][2000];
int Rprev[2000][2000];
int Cnext[2000][2000];
int Cprev[2000][2000];
int dpR[2000][2000];
int dpC[2000][2000];

signed main(){
    FASTER;
    int n,m;cin>>n>>m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    
    for(int i=0;i<n;i++){
        int last=m-1;
        for(int j=m-1;j>=0;j--){
            if(v[i][j]=='.')Rnext[i][j]=last;
            else last=j-1;
        }
    }
    for(int i=0;i<n;i++){
        int last=0;
        for(int j=0;j<m;j++){
            if(v[i][j]=='.')Rprev[i][j]=last;
            else last=j+1;
        }
    }
    
    
    for(int j=0;j<m;j++){
        int last=n-1;
        for(int i=n-1;i>=0;i--){
            if(v[i][j]=='.')Cnext[i][j]=last;
            else last=i-1;
        }
    }
    for(int j=0;j<m;j++){
        int last=0;
        for(int i=0;i<n;i++){
            if(v[i][j]=='.')Cprev[i][j]=last;
            else last=i+1;
        }
    }
    
    
    for(int i=0;i<n;i++){
        dpR[i][0]=(v[i][0]=='.');
        for(int j=1;j<m;j++){
            dpR[i][j]=dpR[i][j-1]+(v[i][j]=='.');
        }
    }
    for(int j=0;j<m;j++){
        dpC[0][j]=(v[0][j]=='.');
        for(int i=1;i<n;i++){
            dpC[i][j]=dpC[i-1][j]+(v[i][j]=='.');
        }
    }
    
    int ans=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='#')continue;
            int r=Rnext[i][j];
            int l=Rprev[i][j];
            int d=Cnext[i][j];
            int u=Cprev[i][j];
            int mx=-1;
            mx+=dpR[i][r]-(l?dpR[i][l-1]:0);
            mx+=dpC[d][j]-(u?dpC[u-1][j]:0);
            ans=max(ans,mx);
        }
    }
    
    cout<<ans;
}