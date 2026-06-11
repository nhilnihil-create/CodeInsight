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

int check(int x) {
    if(x == 1){
        return 300000;
    }else if(x == 2){
        return 200000;
    }else if(x == 3){
        return 100000;
    }else{
        return 0;
    }
}

int main()
{
    int x, y;
    cin >> x >> y;
    int prize = 0;
    prize += check(x);
    prize += check(y);
    if(x == 1 && y == 1) {
        prize += 400000;
    }
    cout << prize << endl;
}