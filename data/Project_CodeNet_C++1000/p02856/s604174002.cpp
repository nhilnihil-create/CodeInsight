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


int main()
{
    int m;
    cin >> m;
    vector<lP> dc(m);
    rep(i, m){ cin >> dc[i].first >> dc[i].second;}

    ll dd = 0;
    ll keta = 0;
    rep(i, m){
        dd += dc[i].first *dc[i].second;
        keta += dc[i].second;
    }

    ll keta_up = 0;
    ll keta_matu = 0;
    while(dd >= 10){
        keta_up += dd/10;
        keta_matu = dd%10;
        dd /= 10;
        dd += keta_matu;
    }



    cout << keta-1+keta_up << endl;
}

