#include<bits/stdc++.h>
// #define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
#define MOD 1000000007
using namespace std;
using ll = long long;
typedef vector<int> vi;

signed main() {
    int n;
    cin >> n;
    int x;
    x = n % 10;
    if(x == 2 || x == 4 || x == 5 || x == 7 || x == 9){
        cout << "hon" << endl;
    }else if(x == 3){
        cout << "bon" << endl;
    }else{
        cout << "pon" << endl;
    }
}