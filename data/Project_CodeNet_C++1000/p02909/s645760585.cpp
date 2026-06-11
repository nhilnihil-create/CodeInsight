#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using p = pair<int, int>;
#define INF 1001001001
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repX(i, n ,x) for (int i = x; i < (int)(n); ++i)
#define repBack(i, n) for (int i = n; i >= 0; --i)
#define dup(x,y) (((x)+(y)-1)/(y))

int main() {
    string S;
    cin >> S;
    if(S[0]=='S')cout << "Cloudy" << endl;
    if(S[0]=='C')cout << "Rainy" << endl;
    if(S[0]=='R')cout << "Sunny" << endl;
    
    return 0;
}