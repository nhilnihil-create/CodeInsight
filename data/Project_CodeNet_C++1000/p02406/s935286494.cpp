#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    for (int i=1;i<=n;i++){
        if (i%3==0){
            cout << " " << i;
        } else {
            int x = i;
            for (int f = 0;!f;) {
                if (x%10==3){
                    cout << " " << i;
                    f = 1;
                }
                if (x < 1) f = 1;
                x /= 10;
            }
        }
    }
    cout << endl;
    return 0;
}