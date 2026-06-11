#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main(void){

    int64_t x; cin >> x;

    int sum, sum_2;
    sum = x / 500;
    x -= sum*500;
    sum *= 1000;
    
    sum_2 = x/5;
    sum += sum_2 * 5;
    cout << sum << endl;

    return 0;
}