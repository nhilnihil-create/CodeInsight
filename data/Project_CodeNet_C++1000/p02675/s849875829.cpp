#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main(void){

    int N;
    cin >> N;
    N %= 10;

    if(N == 3){
        cout << "bon\n";
    } else if(N == 0 || N == 1 || N == 6 || N == 8){
        cout << "pon\n";
    } else {
        cout << "hon\n";
    }

    return 0;
}