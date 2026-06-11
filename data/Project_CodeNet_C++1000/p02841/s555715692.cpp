#include <bits/stdc++.h>

using namespace std;
#define repr(i,a,b) for (int i=a; i<b; i++)
#define rep(i,n) for (int i=0; i<  n; i++)
 
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const long long INF = 1LL << 60;


int main () {
    int M1, D1, M2, D2;

    cin >> M1 >> D1 >> M2 >> D2;

    if(M2-M1 ==1 || M1==12 && M2 ==1)cout << "1" << endl;
    else cout <<"0" << endl;


}