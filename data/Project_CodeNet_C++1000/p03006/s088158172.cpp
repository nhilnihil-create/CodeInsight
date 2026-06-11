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





*/
bool ball_exist(ll x, ll y, vector<lP> &ball, vector<bool>& watched){
    for (int i = 0; i < ball.size(); i++){
        if (ball[i].first == x && ball[i].second == y){
            watched[i] = true;
            return true;
        }
    }
    return false;
}

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
    for (int i = 0; i < diff.size(); i++)
    {
        ll p = diff[i].first;
        ll q = diff[i].second;
        int tans = 0;
        vector<bool> watched(n);
        for (int j = 0; j < n; j++)
        {   
            if(watched[j]) continue;
            watched[j] = true;
            ll x = ball[j].first;
            ll y = ball[j].second;
            while(ball_exist(x, y, ball, watched)) x+=p, y+=q;
            x = ball[j].first;
            y = ball[j].second;
            while(ball_exist(x, y, ball, watched)) x-=p, y-=q;
            tans++;
        }
        //cout << p << q << pat.size() << endl;
        ans = min(ans, tans);
    }
    cout << ans << endl;
}

