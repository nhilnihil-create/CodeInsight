#include <bits/stdc++.h>
using namespace std;
//型名省略
typedef long long ll;
typedef vector<long long> vl;
typedef vector<vector<long long>> vvl;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef vector<string> vs;
//マクロ
#define rep(i,n) for(ll i = 0; i < (ll) n; i++)
#define rep2(i,x,n) for(ll i = (ll) x; i < (ll) n; i++)
#define all(A) A.begin(), A.end()
//正誤判定
void Yes(bool ans){cout << (ans? "Yes" : "No") << endl;}
void YES(bool ans){cout << (ans? "YES" : "NO") << endl;}


//main関数
int main() {
    ll a,b,c,d; cin >> a >> b >> c >> d;

    while(true){
        c -= b;
        if(c <= 0) {
            cout << "Yes" << endl;
            return 0;
        }
        a -= d;
        if(a <= 0){
            cout <<"No" << endl;
            return 0;
        }
    }
}