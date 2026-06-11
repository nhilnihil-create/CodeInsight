#include <iostream>
using namespace std;

int main()
{
    int M, D;
    cin >> M >> D;
    int count = 0;
    for(int m = 1; m <= M; m++) {
        for(int d = 1; d <= D; d++) {
            int d1 = d % 10;
            int d10 = d / 10;
            if(d1 >= 2 && d10 >= 2 && d1*d10 == m) {
                count += 1;
            }
        }
    }
    cout << count << endl;
    return 0;
}