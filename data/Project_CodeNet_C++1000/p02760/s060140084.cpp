#include <bits/stdc++.h>
#define rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (int)(a) ; i < (int)(b) ; i++)


#define SZ(x) ((int)(x).size())


typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
struct Vec{
    double x, y;
};

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
T min(T a, T b)
{
    if (a < b) return a;
    return b;
}

template<class T>
T max(T a, T b)
{
    if (a > b) return a;
    return b;
}

using namespace std;

int board[3][3];
int main()
{
    vector <int> num(100);
    rep(i, 3)rep(k, 3){
        int A;
        cin >> A;
        board[i][k]=A;
        num[A] = 1; 
    }
    int N;
    cin >> N;
    rep(i,N) {
        int m;
        cin >> m;
        if (num[m] == 1){
            rep(i, 3) rep(k, 3) if (board[i][k] == m) board[i][k] = 0;
        }
    }
    
    int row = 0, col = 0, rcross = 0, lcross = 0; 
    rep(i, 3){
        rep(k, 3){
            col += board[i][k];
            row += board[k][i];
            if (i == k) rcross += board[i][k];
            if (i == (2 - k)) lcross += board[i][k];
        }
        if (col == 0 || row == 0) {
            cout << "Yes" << endl;
            return 0;
        }
        col = 0; row = 0;
    }
    if (lcross == 0 || rcross == 0) {
            cout << "Yes" << endl;
            return 0;
    }
    cout << "No" << endl;
    
    return 0;
}
