#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 1; i < n + 1; i++)


int main(){
    ll N;
    cin >> N;

    if(N % 2 == 1){
        cout << 0 << endl;
        return 0;
    }
    
    ll count2 = 0;
    ll count5 = 0;
    ll power2 = 1;
    ll power5 = 2;
    //power2をN以下最大にする。
    while(power2 * 2 <= N){
        power2 *= 2;
    }
    //power5をN以下最大にする。
    while(power5 * 5 <= N){
        power5 *= 5;
    }
    while(power2 > 1){
        count2 += N / power2;
        power2 /= 2;
    }
    while(power5 > 2){
        count5 += N / power5;
        power5 /= 5;
    }

    cout << min(count2, count5) << endl;

    return 0;
}
