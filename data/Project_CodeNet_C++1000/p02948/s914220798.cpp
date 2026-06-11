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
    int n,m;
    cin>>n>>m;
    int day,money;
    //小さい順に出てくる
    priority_queue<P, vector<P>, greater<P>> que;
    
    rep(i,n){
        cin>>day>>money;
        que.emplace(day,money);
    }

    priority_queue<int> able;

    int sum=0;
    REP(i,1,m+1){
        while(!que.empty()){
            tie(day,money)=que.top();
            if(day>i) break;
            que.pop();
            able.emplace(money);
        }
        if(able.empty()) continue;
        sum += able.top();
        able.pop();
    }
    cout<<sum<<endl;
}/*
./problem.exe
*/