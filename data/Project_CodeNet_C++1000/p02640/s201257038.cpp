#include <iostream>
#include <algorithm>
using namespace std;



int main()
{
    int n,leg;
    int b, t;
    cin >> n >> leg;

    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            if (i + j == n && 2 * i + 4 * j == leg) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
   

    cout << "No" << endl;

    return 0;
}