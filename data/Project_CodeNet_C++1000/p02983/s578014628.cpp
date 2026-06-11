
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <utility>
#include <iomanip>  // std::setprecision()
using namespace std;
using ll = long long;
#define rep(i,a,b) for(int i=(a); i<(b); i++)
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;
#define pai 3.14159265358979323846
ll gcd(ll a, ll b){if (a%b == 0)  return(b);else  return(gcd(b, a%b));}
ll lcm(ll a, ll b){return a * b / gcd(a, b);}
/* map<string,int> */
/* 大文字を小文字に変換 tolower*/
/* 小文字を大文字に変換 toupper*/
/* 辞書順 next_permutation(a.begin(),a.end()) */
 
int main() {
    ll l,r;
    cin >> l >> r;
    if (r-l > 2100) {
        cout << 0 << endl;
        return 0;
    }
    int mi = 2100;
    for (ll i = l; i < r; i++) {
        for(ll j = i + 1 ; j<=r; j++) {
            int tmp = (i*j) % 2019;
            mi = min(mi, tmp);
        }
    }
    cout <<  mi << endl;

}