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
    int n;
    cin >> n;
    vi x(n), y(n);
    rep(i, n) {
        cin >> x[i] >> y[i];
    }
    vi v(n);
    rep(i, n) {
        v[i] = i;
    }
    ll sum = 0;
    long double ave = 0;
    do {
        rep(i, n-1) {
            sum = (x[v[i]]-x[v[i+1]])*(x[v[i]]-x[v[i+1]]) + (y[v[i]]-y[v[i+1]])*(y[v[i]]-y[v[i+1]]);
            ave += pow(sum, 0.5);
        }
    } while(next_permutation(v.begin(), v.end()));
    rep(i, n) {
        ave /= i+1;
    }
    printf("%.7Lf", ave);
    return 0;
}