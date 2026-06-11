#include <iostream>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;



int main() {
    int h, a;
    cin >> h >> a;
    cout << (h + a - 1) / a << endl;

    return 0;
}
