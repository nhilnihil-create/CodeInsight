#include <bits/stdc++.h>//Carefully Crafted by hetp111
using namespace std;
#define int long long
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
ifstream cinn("in.txt");ofstream coutt("out.txt");
int poww(const int &a,int b,const int &m=MOD){if(b==0)return 1;int x=poww(a,b/2,m);x=x*x%m;if(b&1)x=x*a%m;return x;}
int ceil(const int &a,const int &b){return (a+b-1)/b;}
////Read:
//Use __builtin_popcountll for ll;
//Check corner cases, n==1;
//
////Some function:
//__builtin_popcountll(), 


signed main(){
    FASTER;
    int n;cin>>n;
    vi v(n);cin>>v;
    
    vi pre(n),suf(n);
    pre[0]=v[0];
    for(int i=1;i<n;i++){
        pre[i]=max(pre[i-1],v[i]);
    }
    suf[n-1]=v[n-1];
    for(int i=n-2;i>=0;i--){
        suf[i]=max(suf[i+1],v[i]);
    }
    
    for(int i=0;i<n;i++){
        int a=0,b=0;
        
        if(i)a=pre[i-1];
        if(i+1<n)b=suf[i+1];
        cout<<max(a,b)<<"\n";
    }
}

