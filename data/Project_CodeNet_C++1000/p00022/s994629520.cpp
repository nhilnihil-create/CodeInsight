#include <iostream>
using namespace std;

int main () {

int n = -1, max = 0, cum = 0;


cin >> n;

int foo[5000];

    while (n) {

    for (int i = 0; i < n; i++) {

        cin >> foo [i];

        if (i == 0)
            max = foo [i];

        if (cum < 0)
            cum = 0;

            cum += foo[i];


        if (cum > max)
            max = cum;

        }

    cout << max << endl;

    max = 0;
    cum = 0;

    cin >> n;

    }


    return 0;

}