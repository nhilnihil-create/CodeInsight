#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main(void){

    int N; cin >> N;
    N %= 1000;
    N = 1000 - N;
    if(N == 1000) N = 0;
    cout << N << endl;

    return 0;
}