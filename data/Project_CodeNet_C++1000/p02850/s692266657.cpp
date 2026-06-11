//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
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

template <typename T>
bool chmax(T &a, const T& b) {if (a < b) {a = b;return true;}return false;}

int main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cout << fixed << setprecision(10);
    int n;
    cin>>n;
    vector<P> a(n);
    vector<vector<int>> g(n,vector<int>(0));
    int x,y;
    rep(i,n-1){
        cin>>x>>y;
        a[i]=P(x-1,y-1);
        g[x-1].emplace_back(y-1);
        g[y-1].emplace_back(x-1);
    }
    int num_col=0;
    int par=-1;
    rep(i,n){
        x=g[i].size();
        if(chmax(num_col,x)) par=i;
    }
    cout<<num_col<<endl;
    map<P,int> col;
    int cnt=0;
    queue<P> que;
    que.emplace(par,0);
    while(cnt<n-1){
        tie(x,y)=que.front();
        que.pop();
        int now=1;
        for(auto z:g[x]){
            if(col[P(x,z)] || col[P(z,x)]) continue;
            if(now==y) now ++;
            col[P(x,z)]=now;
            cnt ++;
            que.emplace(z,now);
            now ++;
        }
    }
    rep(i,n-1){
        tie(x,y)=a[i];
        cout<<max(col[P(x,y)],col[P(y,x)])<<endl;
    }
}/*
./problem.exe
*/
