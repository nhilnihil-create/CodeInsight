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
    string S,T;
    cin >> S >> T;
    int A,B;
    cin >> A >> B;
    string U;
    cin >> U;
    if(S==U){
        cout << A-1 << " " << B << endl;
    }else{
        cout << A << " " << B-1 << endl;
    }
    
    return 0;
}