#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a, b, c, k;
    cin >> a >> b >> c >> k;

    while (k > 0) {
        if (a >= b) {
            b *= 2;
            k--;
            continue;
        }
        if (b >= c) {
            c *= 2;
            k--;
            continue;
        }
        break;
    }

    string result = (a < b && b < c) ? "Yes" : "No";

    cout << result << endl;
    
    return 0;
}
