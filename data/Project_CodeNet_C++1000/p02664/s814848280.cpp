#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;


int main() {
    int pd_counter = 0;
    int d_counter = 0;
    int point = 0;
    string T = "初期化";
    cin >> T;
    for (int i = 0; i < T.size(); i++) {
        //mujyoukennniDkitara+1
        if (T[i] == '?') {
            if (T[i - 1] == 'P') {
                T[i] = 'D';
            }
            else if (T[i + 1] == 'D') {
                T[i] = 'P';
            }
            else if (T[i + 1] == '?') {
                T[i] = 'P';
            }
            else{
                T[i] = 'D';
            }
        }
    }
    cout << T << endl;

    return 0;
}