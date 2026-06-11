#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm> // sort
#include <iomanip>
#include <map>
#include <list>
#include <bits/stl_numeric.h>

#define DEBUG 0
#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll MOD = 1000000007;
static const ll INF = 1000000000000000000LL;
using namespace std;


//方針: x と(-y)を作成したい
//x,yをどう選べば最大値が得られるか

//-4,-2,0,1,2,3
// 4
// 3 -4 -> 7
// -2 2 -> -4
//負と正で負をつくる
//正と負で正をつくる



//いい感じに負と正の数をあわせて、どん

int main(){
    ll N;
    cin >> N;
    vector <ll> a(N);
    REP(i,N)cin >> a[i];
    sort(a.begin(),a.end());
    ll pra = 0;
    ll mai = 0;
    REP(i,N)
    {
        //if(a[i] == 0)
        //{
        //    if(pra == 0)++pra;
        //    else ++mai;
        //}
        if(a[i] <= 0)
        {
            ++mai;
        }
        else
        {
            ++pra;
        }
    }
    ll l = 0;
    ll r = N-1;
    vector <pair<ll, ll >> p(N-1);
    REP(i,N-2)
    {
        if(pra > mai)
        {
            p[i].first = a[l];
            p[i].second = a[r];
            //負をつくる
            a[l] = a[l] - a[r];
            --pra;
            --r;
        }
        else
        {
            p[i].first = a[r];
            p[i].second = a[l];
            //正をつくる
            a[r] = a[r] - a[l];

            --mai;
            ++l;
        }
    }
    //最後の1回は逆にする
    p[N-2].first = a[r];
    p[N-2].second = a[l];

    cout << a[r] - a[l] << endl;
    REP(i,N-1)
    {
        cout << p[i].first << " " << p[i].second << endl;
    }

    return 0;
}
