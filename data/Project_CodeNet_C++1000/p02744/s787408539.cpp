#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int main(){
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    queue<string> que;
    que.push("a");
    int cnt = 1;
    set<string> ans;
    while(1){
        string fa = que.front();
        if(que.front().size() >= n) break;
        char maxc = 'a';
        rep(i,fa.size()){
            chmax(maxc,fa[i]);
        }
        rep(i,int(maxc - 'a' + 2)){
            que.push(fa + char('a' + i));
        }
        que.pop();
        cnt++;
    }
    while(!que.empty()){
        cout << que.front() << endl;
        que.pop();
    }
    return 0;
}