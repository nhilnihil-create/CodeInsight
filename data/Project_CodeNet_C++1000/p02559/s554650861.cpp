// lcmとか__builtin_popcountとかはg++ -std=c++17 default.cppみたいなかんじで
// g++ hoge.cpp -std=c++17 -I . でコンパイルできる
// -fsanitize=undefinedでオーバーフロー検出
#include <bits/stdc++.h>
#include <atcoder/all>

#define mod 1000000007
#define INF LLONG_MAX
#define ll long long
#define ln cout<<endl
#define Yes cout<<"Yes"<<endl
#define NO cout<<"NO"<<endl
#define YES cout<<"YES"<<endl
#define No cout<<"No"<<endl
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
using namespace std;
using namespace atcoder;
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};
typedef pair<ll,ll> P;



int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    int a,b,c,d,m,n,maxi=0,f=0,mini=INF,sum=0;
    int k;
    int g,e;
    ll q;
    cin>>n>>q;
    fenwick_tree<ll> tree(n);
    rep(i,n){
        cin>>a;
        tree.add(i,a);
    }
    rep(i,q){
        cin>>a;
        if(a==0){
            cin>>a>>b;
            tree.add(a,b);
        }else{
            cin>>a>>b;
            cout<<tree.sum(a,b)<<endl;
        }
    }

    return 0;
}
