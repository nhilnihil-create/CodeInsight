#include <iostream>
#include <vector>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
using ll = long long;

using namespace std;



int main() {
    int x;
    cin >> x;
    int s = x/100;
    int t = x % 100;
    if(t > s*5) {
        cout << 0 << endl;
        return 0;
    }
    while(s > 0) {
        t -= 5;
        --s;
    }
    if(t > 0) {
        cout << 0 << endl;
        return 0;
    }
    cout << 1 << endl;

    return 0;
}
