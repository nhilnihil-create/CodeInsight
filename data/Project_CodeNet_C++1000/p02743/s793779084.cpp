#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    long double a, b, c; cin >> a >> b >> c;
    if(1+sqrt(b/a)<sqrt(c/a)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}