#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using p = pair<int,int>;
static const long long INF = 100000000;
int main(){
    int a,b;
    cin >> a >> b;
    if (a % b == 0){
        cout << a/b << endl;
    }
    else {
        cout << a/b + 1 << endl;
    }
    return 0;
}