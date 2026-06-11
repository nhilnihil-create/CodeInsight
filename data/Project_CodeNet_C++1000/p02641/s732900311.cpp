#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define pb push_back
#define ALL(v) v.begin(),v.end()
const long long INF = 1LL << 60; // 仮想的な無限大の値;
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;
int main()
{
    int X, N;
    cin >> X >> N;
    set<int> s;
    int max = 0;
    int min = INT_MAX;
    if(N == 0)
    {
        cout << X << endl;
        return 0;
    }
    rep(i, N)
    {
        int a;
        cin >> a;
        s.insert(a);
        chmax(max, abs(a-X));
    }
    int ans = -1;
    rep2(i, 0, 105)
    {
        int cand = X-i;
        int cand2 = X+i;
        if(s.find(cand) == s.end())
        {
            ans = cand; break;
        }
        if(s.find(cand2) == s.end())
        {
            ans = cand2; break;
        }
    }    
    cout << ans << endl;
    return 0;
}