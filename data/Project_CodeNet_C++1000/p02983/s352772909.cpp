#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
using P = pair <int, int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

ll MOD = 1000000007;
ll INF =1<<29;

int main(){
    int l,r;
    cin >> l >> r;
    int a = l/2019;
    int b = r/2019;
    int x = l%2019;
    int y = r%2019;
    if(x==0||y==0){
        cout << 0 <<endl;
        return 0;
    }
    if(a<b){
        cout << 0 << endl;
        return 0;
    }
    int mi= 1000000000;
    for(int i = x;i<=y-1;++i){
           for(int j = i+1;j<=y;++j){
               mi = min((i*j)%2019,mi);
           }
    }
    cout << mi << endl;
}