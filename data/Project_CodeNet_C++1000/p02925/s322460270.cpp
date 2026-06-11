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


int main(){
 //ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 cout << fixed << setprecision(10);
    int n;
    cin>>n;
    int x;
    vector<queue<int>> b(n);
    rep(i,n)rep(j,n-1){
        cin>>x;
        x --;
        b[i].emplace(x);
    }
    set<int> seen;
    int ans=-1;
    bool f=1;
    while(f){
        f=0;
        rep(i,n){
            if(b[i].empty()) continue;
            int op=b[i].front();
            if(op<i) continue;
            if(seen.count(op) || seen.count(i)) continue;
            if(b[op].front() != i) continue;
            f=1;
            b[i].pop();
            b[op].pop();
            seen.emplace(op);
            seen.emplace(i);
        }
        ans ++;
        seen.clear();
    }
    rep(i,n){
        if(!b[i].empty()){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;
}/*
./problem.exe
*/
