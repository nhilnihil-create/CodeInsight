#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
    ll n,k;
    cin >> n >> k;
    ll div = k;
    ll tmp = n,tmp2=0;
    int cnt = 0;

    while(tmp != 0){
        tmp2 = tmp % div;
        // cout << tmp2 << endl;
        div *= k;
        tmp -= tmp2;
        cnt++;
    }

    cout << cnt << endl;
    return 0;
}