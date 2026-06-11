#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using P = pair<int,int>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int N;
    cin>>N;
    queue<string> q;
    q.push("a");
    while((int)q.front().size()!=N){
        string s = q.front();
        q.pop();
        int n = s.size();
        int t = 0;
        for(auto x:s){
            int m = x - 'a';
            chmax(t,m);
        }
        rep(i,t+2){
            char c = 'a'+i;
            string l = s + c;
            q.push(l);
        }
    }
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
}