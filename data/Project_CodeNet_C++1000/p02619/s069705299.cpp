#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;
typedef pair<int, int> P;

const int D = 365;
vector<int> C(26), ans(D, 0), last(26,-1);
vector<vector<int>> S(D, vector<int>(26));

void debug1()
{
    //rep(i,26) cout << C[i] << " "; cout << endl;
    rep(i,D){
        rep(j,26)cout << S[i][j] << " ";
        cout << endl;
    }
}
void rand_init()
{
    rep(i,26) C[i] = rand() % 100;
    rep(i,D) rep(j,26) S[i][j] = rand() % 20000;
}
void input()
{
    int tmp;
    cin >> tmp;
    if(tmp == 0)
    {
      rand_init();
      return;
    }
    rep(i,26) cin >> C[i];
    rep(i,D)rep(j,26) cin >> S[i][j];
    rep(i,D) cin >> ans[i]; rep(i,D) ans[i]--; //B,C問題用
}
void output()
{
    for(auto x : ans)
        cout << x+1 << "\n";
}
int calc(vector<int> &vec)
{
    int score = 0;
    rep(i,D)
    {
        int cur = vec[i];
        score += S[i][cur];
        last[cur] = i;
        rep(j,26)
        {
            score -= C[j] * (i - last[j]);
        }
        cout << score << endl;
    }
    return score;
}
void greedy()
{
    rep(i,D)
        rep(j,26)
            if(S[i][j] > S[i][ans[i]])
                ans[i] = j;
}
void incremental()
{
    rep(t, 10000)
    {
        int d = rand() % D, q = rand() % 26;
        vector<int> old = ans;
        ans[d] = q;
        if(calc(ans) < calc(old))
            ans = old;
    }
}
void solve()
{
  greedy();
  incremental();
}
void rand_test(int r)
{
    rep(q,r)
    {
        rand_init();
        //debug1();
        solve();
        cout << 1000000 - calc(ans) << endl;
    }
}
int main()
{
    input();
    calc(ans);
    //rand_test(10);
    //solve();
    //output();
    return 0;
}