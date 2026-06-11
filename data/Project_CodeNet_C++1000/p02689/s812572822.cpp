#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#define REP(i,a) for (int i = 0;i < (a);++i)
#define FOR(i,a,b) for (int i = (a);i < (b); ++i)
#define FORR(i,a,b) for (int i = (a);i >= (b); --i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SORT(list) sort(ALL((list)));
#define MOD 1000000007
using namespace std;
using ll = long long;
int main(){
    int n,m;
    cin >> n>> m;
    vector<ll>h(n);
    vector<vector<ll>>graph(n);
    REP(i,n)cin >> h[i];
    vector<ll>a(m),b(m);
    REP(i,m){
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        graph[a[i]].push_back(b[i]);
        graph[b[i]].push_back(a[i]);
    }
    ll answer = 0;
    REP(i,n){
        bool ok = true;
        REP(j,graph[i].size()){
            if(h[i] <= h[graph[i][j]])ok=false;
        }
        if(ok)answer++;
    }
    cout << answer << endl;

    return 0;
}