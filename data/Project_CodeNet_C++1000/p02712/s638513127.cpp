#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main(void){

    int n; cin >> n;
    
    int i=1;
    int64_t sum = 0;
    rep(j, n){
        if(i % 3 == 0 || i % 5 == 0){
        } else {
            sum += i;
        }
        i++;
    }
    cout << sum << endl;

    return 0;
}