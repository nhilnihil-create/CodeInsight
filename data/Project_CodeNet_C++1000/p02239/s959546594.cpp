#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <map>
#include <bitset>
#include <cstdio>
#include <set>
#include <stack>
#include <queue>
#include <cassert>
#include <numeric>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for (ll i=(a),__last_##i=(b);i<__last_##i;i++)
#define RFOR(i,a,b) for (ll i=(b)-1,__last_##i=(a);i>=__last_##i;i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define __GET_MACRO3(_1, _2, _3, NAME, ...) NAME
#define rep(...) __GET_MACRO3(__VA_ARGS__, FOR, REP)(__VA_ARGS__)
#define rrep(...) __GET_MACRO3(__VA_ARGS__, RFOR, RREP)(__VA_ARGS__)
template<typename T> istream &operator>>(istream &is, vector<T> &v){ for (auto &x : v) is >> x; return is; }
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    REP(i,v.size()){if(i)os<<" ";os<<v[i];}return os;}
template<typename T> ostream& operator<<(ostream& os, const vector<vector<T>>& v) {
    REP(i,v.size()){if(i)os<<endl;os<<v[i];}return os;}
#define vi vector<int>
#define vii vector<vector<int>>
#define mii map<int,int>
#define Sort(v) sort(v.begin(),v.end())
#define Reverse(v) reverse(v.begin(),v.end())
#define ALL(a)  (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
//#define int ll

const int md = 1000000007;
const int INF = 1<<30;



int main(){
    int n; cin >> n;
    vector<vector<int>> e(n);


    rep(i,n){
        int s; cin >> s;
        int tmp; cin >> tmp;
        rep(j,tmp){
            int to; cin >> to;
            e[i].push_back(to-1);
        }
    }

    vi ans(n,-1);
    rep(i,n){
        //if(i != 3) continue;
        queue<pair<int,int>> bfs;
        bfs.emplace(0,0);
        vector<bool> visit(n,false);
        while(!bfs.empty()){
            auto tmp = bfs.front();
            if(tmp.first == i) {
                ans[i] = tmp.second;
                break;
            }
            visit[tmp.first] = true;
            bfs.pop();

            rep(j,e[tmp.first].size()){
                if(!visit[e[tmp.first][j]]) {
                    //cout << j << endl;
                    bfs.emplace(e[tmp.first][j],tmp.second+1);
                }
            }
        }

    }

    rep(i,n){
        cout << i+1 << " " << ans[i] << endl;
    }
}

