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
string s;
int dp[100000][13];

int f(int i,int sum){
    if(i==n)return sum==5;
    int &ans=dp[i][sum];
    if(ans!=-1)return ans;
    ans=0;
    if(s[i]!='?'){
        ans=f(i+1,(sum*10+s[i]-'0')%13);
    }else{
        for(int j=0;j<10;j++)ans=(ans+f(i+1,(sum*10+j)%13))%MOD;
    }
    return ans;
}

signed main(){
    FASTER;
    cin>>s;
    n=s.size();
    memset(dp,-1,sizeof dp);
    cout<<f(0,0);
}

