#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main() {
    string S; cin >> S;
    int N = S.length(), cnt = 0;
    if (N % 2 == 0) {
        int p = N / 2;
        int i = 0, j = N - 1;
        while(i < N / 2) {
            if (S[i] != S[j]) cnt++;
            i++, j--;
        }
    }
    else {
        int p = N / 2;
        int i = 0, j = N - 1;
        while(i < N / 2) {
            if (S[i] != S[j]) cnt++;
            i++, j--;
        }
    }
    cout << cnt << endl;
}
