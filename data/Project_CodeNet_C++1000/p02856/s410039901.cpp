//競技プログラミング用のテンプレート
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <math.h>

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

using namespace std;
using ll = long long int;
using p = pair<int, int>;
using pl = pair<ll, ll>;
using v = vector<int>;
using vd = vector<double>;
using vs = vector<string>;
using vl = vector<ll>;
using vpl = vector<pl>;

int main()
{
    int m;
    cin >> m;
    vpl dc(m);
    rep(i, m)
    {
        cin >> dc[i].first >> dc[i].second;
    }
    ll round = 0;
    ll totallen = 0;
    ll total = 0;
    rep(i, m)
    {
        totallen += dc[i].second;
        total += dc[i].first * dc[i].second;
    }
    round = (totallen - 1) + ( (total - 1) / 9);
    cout << round << endl;
}