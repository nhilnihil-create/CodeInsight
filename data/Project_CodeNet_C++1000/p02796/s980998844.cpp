#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}

//例えば、a < bとしたとき昇順ソートとなる
bool cmp(const P &a, const P &b){
    return a.second < b.second;
}

int main()
{
    int n;
    cin >> n;
    vector<P> range(n);
    rep(i, n){
        int x, l;
        cin >> x >> l;
        range[i].first = x-l;
        range[i].second = x+l;
    }
    //secondが最も小さいものを選ぶ
    sort(range.begin(), range.end(), cmp);

    int hand = -MOD;
    int ans = 0;
    rep(i, n){
        if ( hand <= range[i].first ){
            hand = range[i].second;
            ans++;
        }
    }
    cout << ans << endl;
}

