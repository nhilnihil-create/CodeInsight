#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    while (true) {
        int x, y;
        cin >> x >> y;
        if (!x && !y) break;
        cout << min(x, y) << " " << max(x, y) << "\n";
    }
}