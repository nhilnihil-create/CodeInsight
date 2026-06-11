#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using p = pair<int, int>;
#define INF 1001001001
#define PI 3.14159265359
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repX(i, n , x) for (int i = (int)(x); i < (int)(n); ++i)
#define repB(i, n) for (int i = n; i >= 1; --i)
#define repBX(i, n , x) for (int i = (int)(n); i >= int(X); --i)
#define dup(x,y) (((x)+(y)-1)/(y))

int main() {
    string S;
    cin >> S;
    if(S[2]==S[3]&&S[4]==S[5]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
    return 0;
}