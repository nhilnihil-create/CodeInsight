#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)
int main() {
    int x, y;
    cin >> x >> y;
    int money[206];
    rep(i, 206) {
        if ( i == 1 )      money[i] = 300000;
        else if ( i == 2 ) money[i] = 200000;
        else if ( i == 3 ) money[i] = 100000; 
        else               money[i] = 0;
    }
    if ( x == 1 && y == 1 ) cout << 300000 + 300000 + 400000 << endl;
    else                    cout << money[x] + money[y] << endl;
    return 0;
}
