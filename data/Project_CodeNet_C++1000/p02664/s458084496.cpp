#include <bits/stdc++.h>
#define div1 1000000007
const long long INF = 1LL << 60;
using namespace std;
typedef long long ll;
typedef long double ld;
// a>b -> a==b;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// a<b -> a==b;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(void)
{
    ll i;
    string T;

    cin >> T;

    for(i=0; i<T.size(); i++){
        if(T[i]=='?') cout << "D";
        else cout << T[i];
    }
    cout << endl;

    return 0;
}