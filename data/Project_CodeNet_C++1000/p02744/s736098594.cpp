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

ll n ;
string s = "Aabcdefghij";
string t = "a";
void func(ll cnt, string a){
    ll MAX = 1;
    for(ll i = 0; i < a.length(); i++){
        char d = a[i];
        ll e = d-96;
        MAX = max(MAX, e);
    }
    if(cnt < n){
        for(ll i = 1; i <= MAX+1; i++){
            string c = a + s[i];
            func(cnt+1, c);
        }
    }
    if(cnt == n)
        cout << a << endl;
}

int main(void){
    cin >> n;
    func(1, t);
    return 0;
}
