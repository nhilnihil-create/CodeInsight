#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> lP;

ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}

/*
全探索の場合
 p,qの全探索でout
 差分の数ならN^2よ？

一次元なら座標の差分をとって最大公約数とればpが定まる

次元圧縮してset?
 qx - pyのパターン数を探す
  1,1 3,3, 5,5 6,6 を1としてカウントしてしまうぞ

選んだ物に対して、同一グループを探索

木を生成する解法も解くぞ
*/
void dfs(int v, vector<bool>& b, vector<vector<int>>& root);
int main()
{
    int n;
    cin >> n;
    vector<lP> ball(n);
    rep(i, n){
        cin >> ball[i].first >> ball[i].second;
    }

    vector<lP> diff;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (i == j) continue;
            ll dx = ball[i].first - ball[j].first;
            ll dy = ball[i].second - ball[j].second;
            diff.push_back({dx, dy});
        }
    }
    
    int ans = n;
    for (int d = 0; d < diff.size(); d++)
    {
        vector<vector<int>> root(n);
        vector<bool> visited(n);
        int tans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                if (i==j) continue;
                ll dx = ball[i].first - ball[j].first;
                ll dy = ball[i].second - ball[j].second;
                if ((diff[d].first == dx && diff[d].second == dy) ||
                (diff[d].first == -dx && diff[d].second == -dy))
                {
                    root[i].push_back(j);
                    root[j].push_back(i);
                }
            }   
        }
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == false){
                dfs(i, visited, root);
                tans++;
            }
        }
        ans = min(tans, ans);
    }
    cout << ans << endl;
}

void dfs(int v, vector<bool>& b, vector<vector<int>>& root){
    b[v] = true;
    for (auto next: root[v])
    {
        if(b[next] == true) continue;
        dfs(next,b,root);        
    }
    
}
