#include <bits/stdc++.h>
 
using namespace std;
#define repr(i,a,b) for (int i=a; i<b; i++)
#define rep(i,n) for (int i=0; i<  n; i++)
 
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
 
const long long INF = 1LL << 60;
#define PI 3.14159265359 
bool dp[100100];


int main () {
    string S, T, U;
    cin >> S >> T;

    int A, B;
    cin >> A >> B;

    cin >> U;
    if( U == S) A-=1;
    if( U == T) B-=1;

    cout << A << " " << B << endl;
}