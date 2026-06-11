// 173

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <iomanip>
#include <climits>
#include <string>
#include <cmath>

using namespace std;
using ll = long long int;
#define NUM 1000000007

int main(){
    ll x, k, d, buf;
    cin >> x >> k >> d;
    x = abs(x);
    buf =  x/d;
    if(buf < k){
        if ((k-buf)%2 == 1) cout << abs(x-(buf+1)*d) << endl;
        else if((k-buf)%2 == 0)cout << abs(x-(buf)*d) << endl;
    }else{
        cout << abs(x-k*d) << endl;
    }
}