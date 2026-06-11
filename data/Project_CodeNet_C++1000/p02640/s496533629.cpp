/*
    飲んだ魔剤で家が建つ。
    created at: 2020-09-23 06:07:24
*/

#include <iostream>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define INF 1000000000

int main()
{
    int X, Y;
    cin >> X >> Y;

    for (int c = 0; c <= X; c++) {
        int t = X - c;
        int sum = 2*c + 4*t;
        
        if (sum == Y) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}
