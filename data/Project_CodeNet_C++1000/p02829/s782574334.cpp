#include<bits/stdc++.h> 
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define endl "\n"
#define mod 1000000007
#define mod2 998244353
#define double long double
#define pb push_back
#define swap(x,y) (x^=y^=x^=y)
#define TC int TESTCASE;cin>>TESTCASE;while(TESTCASE--)
#define oo 1500000000000000000
#define mem(a,b) memset(a,b,sizeof(a))
#define debug1(a) cout<<#a<<" = "<<(a)<<endl;
#define debug2(a,b) cout<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<endl;
#define debug3(a,b,c) cout<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<", "<<#c<<" = "<<(c)<<endl;
#define debug4(a,b,c,d) cout<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<", "<<#c<<" = "<<(c)<<", "<<#d<<" = "<<(d)<<endl;
using namespace std;
 
int modexpo(int x,int p){
    int res = 1;x = x%mod;
    while(p){
        if(p%2)res = res * x;
        p >>= 1;
        x = x*x % mod;
        res %= mod;
    }
    return res;
}
 
int max(int a,int b){return (a>b?a:b);}
 
int min(int a,int b){return (a<b?a:b);}
 
struct edge{int u,v,w;edge(int a,int b,int c){u=a;v=b;w=c;}};
 
struct compare{
    bool operator() (const edge a, const edge b) const{
        if(a.u == b.u){
            if(a.v == b.v){
                return a.w < b.w;
            }
            return a.v < b.v;
        }
        return a.u < b.u;
    }
};

int32_t main(){
    IOS
    int a,b;
    cin >> a >> b;
    cout<<6-a-b<<endl;
} 