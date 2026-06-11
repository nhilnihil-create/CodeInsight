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
//__builtin_popcountll(), 

//abbabbababaaaajjjakaakbbbbbkk
//aaaaaaaaaaaaaaaaaaaaabbbbbbkk

char com(char c){
    if(c=='r')return 'p';
    if(c=='p')return 's';
    if(c=='s')return 'r';
}

signed main(){
    FASTER;
    int n,k;cin>>n>>k;
    int r,s,p;cin>>r>>s>>p;
    map<char,int> cst;
    cst['r']=r;
    cst['s']=s;
    cst['p']=p;
    vector<char> v[k];
    for(int i=0;i<n;i++){
        char c;cin>>c;
        v[i%k].push_back(c);
    }
    
    int ans=0;
    for(int i=0;i<k;i++){
        
        for(int j=0;j<v[i].size();j++){
            int cnt=1;
            char c=v[i][j];
            while(j+1<v[i].size() && v[i][j]==v[i][j+1])cnt++,j++;
            ans+=ceil(cnt,2)*cst[com(c)];
        }
        
    }
    cout<<ans;
}
