#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <iomanip>
#include <vector>
#include <cstring>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uld = unsigned long long;
using P = pair<int,int>;
const ll mod = 1e9+7;
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
template<class T> inline bool chmax(T &a,T& b){if(a < b){a = b; return true;} else return false;}
template<class T> inline bool chmin(T &a,T& b){if(a > b){a = b; return true;} else return false;}
int n,m,q;
vector<int> a,b,c,d;
int score(vector<int> &A){
    int res = 0;
    for(int i=0;i<q;i++){
        if(A[b[i]] - A[a[i]] == c[i]) res += d[i];
    }
    return res;
}
int dfs(vector<int> &A){
    if(A.size() == n){
        return score(A);
    }
    int res = 0;
    int p = 0;
    if(!A.empty()) p = A.back();
    for(int v=p;v<m;v++){
        A.push_back(v);
        res = max(res,dfs(A));
        A.pop_back();
    }
    return res;
}
int main(){
    cin >> n >> m >> q;
    a.resize(q); b.resize(q); c.resize(q); d.resize(q);
    rep(i,q){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        --a[i]; --b[i];
    }
    vector<int> A;
    cout << dfs(A) << endl;
}