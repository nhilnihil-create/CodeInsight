//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
using in = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl
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
    int n,k;
    cin>>n>>k;
    vector<vector<int>> g(n,vector<int>(0));
    int x,y;
    rep(i,n-1){
        cin>>x>>y;
        x --,y --;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    in ans=k;
    queue<int> que;
    vector<bool> seen(n,false);
    que.emplace(0);
    seen[0]=true;
    while(!que.empty()){
        x=que.front();
        que.pop();
        int cnt=1;
        if(x==0) cnt=0;
        for(auto z:g[x]){
            if(seen[z]) continue;
            cnt ++;
            ans *=(k-cnt);
            ans %=MOD;
            seen[z]=true;
            que.emplace(z);
        }
    }
    cout<<ans<<endl;
}/*
./problem.exe
*/