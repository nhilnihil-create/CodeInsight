#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;
typedef int64_t ll;

int main() {
    int X, Y;
    cin >> X >> Y;
    for (int i = 0; i < X + 1; i++){
        if (i * 2 + (X - i) * 4 == Y){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}