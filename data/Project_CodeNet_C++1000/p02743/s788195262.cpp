#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i < (int)(n); i++)
#define Sort(a) sort(a.begin(), a.end())
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
template <class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;} return false;}
template <class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;} return false;}

int main(){
    long double a, b, c;
    cin >> a >> b >> c;
    long double x;
    x = pow(a*b, 0.5);
    //printf("%llf", x+a+b);
    if(a+b+2*x < c) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}