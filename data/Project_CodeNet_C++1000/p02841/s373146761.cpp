#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <map>
#include <bitset>
#include <numeric>
#define ll long long
using namespace std;
using p = pair<ll, ll>;
ll dx[8]={ 0, 1, 0,-1, 1, 1,-1,-1}; // x軸方向への変位
ll dy[8]={ 1, 0,-1, 0, 1,-1, 1,-1}; // y軸方向への変位


int main(void){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a+1==c && d==1)
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}
