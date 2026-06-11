#include <bits/stdc++.h>//Carefully Crafted by hetp111
using namespace std;
#define int long long
#define double long double
#define all(v) (v).begin(),(v).end()
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define MOD 1000000007
#define MOD2 998244353
#define MOD3 1000000009
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

int n,t;
int timee[3001];
int taste[3001];
int dp[3001][3001];

int f(int i,int t){
    if(t<=0 || i>=n)return 0;
    int &ans=dp[i][t];
    if(ans!=-INF)return ans;
    ans=f(i+1,t);
    ans=max(ans,taste[i]+f(i+1,t-timee[i]));
    return ans;
}

signed main(){
    FASTER;
    for(int i=0;i<=3000;i++){
        for(int j=0;j<=3000;j++){
            dp[i][j]=-INF;
        }
    }
    
    cin>>n>>t;
    vii v;
    for(int i=0;i<n;i++){
        cin>>timee[i]>>taste[i];
        v.push_back({timee[i],taste[i]});
    }
    sort(all(v));
    for(int i=0;i<n;i++){
        timee[i]=v[i].first;
        taste[i]=v[i].second;
    }
    cout<<f(0,t);
}