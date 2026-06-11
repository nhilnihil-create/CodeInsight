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
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cout << fixed << setprecision(10);
    int n;
    cin>>n;
    vector<vector<int>> a(n,vector<int>(n-1,0));
    rep(i,n)rep(j,n-1) {cin>>a[i][j];a[i][j]--;}
    vector<int> now(n,0);
    int ans=-1;
    int cnt=1;
    while(cnt){
        cnt=0;
        vector<bool> bat(n,false);
        rep(i,n){
            if(now[i]==n-1) continue;
            int op=a[i][now[i]];
            if(bat[op] || bat[i]) continue;
            if(a[ op ][ now[op] ] != i) continue;
            cnt ++;
            now[i] ++;
            now[op] ++;
            bat[i] =true;
            bat[op]=true;
        }
        ans ++;
    }
    rep(i,n){
        if(now[i]<n-1){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;
}/*
./problem.exe
*/