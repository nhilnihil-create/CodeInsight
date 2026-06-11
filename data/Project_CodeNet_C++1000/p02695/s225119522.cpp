#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(c) (c).begin(), (c).end()
#define pb push_back
#define eb emplace_back
using namespace std;
const long long INF = 1LL<<60; // 仮想的な無限大の値;
using ll = long long;
using P  = pair<int, int>;
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int N, M, Q;
vi x;
int score = 0;
int a[100], b[100], c[100], d[100];
int cal(vi& q)
{
    int ans = 0;
    rep(i, Q)
    {
        if(q[b[i]]-q[a[i]] == c[i]) ans += d[i];
    }
    return ans;
}
void dfs(int v, int p){
    x[p] = v;
    if(++p >= N)
    {
        chmax(score, cal(x));
        return;
    }
    rep2(i, v, M+1)
    {
        dfs(i, p);
    }
}

int main()
{
    
    cin >> N >> M >> Q;
    x.assign(N, 0);
    
    rep(i, Q)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        --a[i];--b[i];
    }

    rep(i, N)
    {
        dfs(i+1, 0);
    }
    cout << score << endl;
    // vi A(N, 1);
    // int ans = 0;
    // int pos = 1;

    // while(1)
    // {
    //     int x = 0;
    //     rep(i, Q)
    //     {
    //         if(A[b[i]]-A[a[i]] == c[i]) x += d[i]
    //     }
    //     chmax(ans, x);
    //     rep2()

    //     bool ok = true;
    //     rep(i, N){
    //         if(A[i] > M) ok = false;
    //     }
    //     if(!ok) 
    //     {
    //         break;
    //     }
    // }
    
    
    return 0;
}

