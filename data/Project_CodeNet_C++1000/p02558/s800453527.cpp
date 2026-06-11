//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define all(v) v.begin(), v.end()
using in = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
const double PI=3.14159265358979323846;
const in MOD = 1000000007;
const in INF=1e18+7;
const int inf=1e9+7;
using P=pair<int,int>;
vector<int> dx={0,1,-1,0};
vector<int> dy={1,0,0,-1};


int main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cout << fixed << setprecision(10);
    int n,q;
    cin>>n>>q;
    int x,y,z;
    
    dsu uf(n);
    rep(i,q){
        cin>>x>>y>>z;
        if(x) cout<<uf.same(y,z)<<endl;
        else  uf.merge(y,z);
    }

}/*
./problem.exe
*/