#include <bits/stdc++.h>

using namespace std;
#define repr(i,a,b) for (int i=a; i<b; i++)
#define rep(i,n) for (int i=0; i<  n; i++)
 
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const long long INF = 1LL << 60;

bool dp[100100];

int main () {
    int X;
    cin >> X;

    rep(i,100100){
        dp[i] = false;
    }
    dp[0] = true;
    repr(i,100,106){
        dp[i] = true;
    }

    repr(i,105,100100){
        if(dp[i-100] ||dp[i-101] ||dp[i-102] ||dp[i-103] ||dp[i-104]|| dp[i-105]){
          dp[i] =true;  
        }
    }

    if(dp[X])cout << "1" << endl;
    else cout << "0" << endl;

}