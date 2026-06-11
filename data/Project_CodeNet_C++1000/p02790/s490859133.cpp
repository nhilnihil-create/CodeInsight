#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;



int main() {
    int a, b;
    cin >> a >> b;
    rep(i,max(a, b)) cout << min(a, b);
    cout << endl;

    return 0;
}
