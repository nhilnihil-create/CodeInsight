#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <utility>
#include <iomanip>  // std::setprecision()
#include <set>
using namespace std;
using ll = long long;
#define rep(i,a,b) for(ll i=(a); i<(b); i++)
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
    int n,l;
    cin >> n >> l;
    ll sum = 0;
    vector <ll> a(n);
    ll mi = 500;
    bool positive = true;
    rep(i,0,n) {
        a[i] = l + i; 
        if (abs(0-a[i]) < mi) {
            mi = abs(0-a[i]);
            if (a[i] < 0) {
                positive = false;
            }
        }
        sum += a[i];
    }
    if (positive) {
        cout << sum -mi << endl;
    } else {
        cout << sum + mi << endl;
    }
}