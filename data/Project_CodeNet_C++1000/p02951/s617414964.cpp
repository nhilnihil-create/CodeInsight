#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using p = pair<int, int>;
#define INF 1001001001
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repX(i, n ,x) for (int i = x; i < (int)(n); i++)
#define repBack(i, n) for (int i = n; i >= 0; i--)
#define dup(x,y) (((x)+(y)-1)/(y))

int main() {
    int A,B,C;
    cin >> A >> B >> C;
    int D = A-B;
    if(C-D<0){
        cout << 0  << endl;
    }else{
    cout << C - D << endl;
    }

    return 0;
}