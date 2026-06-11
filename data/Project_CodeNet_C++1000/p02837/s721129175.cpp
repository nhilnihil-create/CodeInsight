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
//ifstream cinn("in.in");ofstream coutt("out.out");
int poww(const int &a,int b,const int &m=MOD){if(b==0)return 1;int x=poww(a,b/2,m);x=x*x%m;if(b&1)x=x*a%m;return x;}
int ceil(const int &a,const int &b){return (a+b-1)/b;}
////Read:
//Check corner cases, n==1;
//
////Some function:
//__builtin_popcountll(), is_sorted(),

int n;
int a[15];
int x[15][15],y[15][15];

signed main(){
    FASTER;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        for(int j=0;j<a[i];j++){
            cin>>x[i][j]>>y[i][j];
            x[i][j]--;
        }
    }
    
    int ans=0;
    for(int ii=1;ii<(1<<n);ii++){
        bool ok=1;
        for(int i=0;i<n;i++){
            if((ii&(1<<i))==0)continue;
            for(int j=0;j<a[i];j++){
                if( ((ii>>x[i][j])&1)^y[i][j] )ok=0;
                //    present/absent ^ liar/notLiar
            }
        }
        if(ok)ans=max(ans,(int)__builtin_popcountll(ii));
    }
    
    cout<<ans;
}

