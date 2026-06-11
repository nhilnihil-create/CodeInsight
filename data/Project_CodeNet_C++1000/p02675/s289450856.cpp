#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e8;

//---main---------------------------------------------
int main(){
    //main
    int N;
    cin >> N;

    int a = N%10;
    if(a == 3) cout << "bon" << endl;
    else if(a < 2 || a==6||a==8) cout << "pon" << endl;
    else cout << "hon" << endl;
    
    return 0;
}