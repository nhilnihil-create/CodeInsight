#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int x;
    cin >> x;
    int y = sqrt(x) + 1;

    int ans;
    bool flag = true;

    //cout << "test y = " << y << endl;

    for (int i = x; i < 100005; i++) {
        flag = true;
        for (int j = 2; j < y; j++) {
            if (i % j == 0)
                flag = false;
        }
        if (flag) {
            ans = i;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}