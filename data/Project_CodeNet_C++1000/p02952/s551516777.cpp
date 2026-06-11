#include <bits/stdc++.h>;
using namespace std;

int main() {
    int N, num;
    num=0;
    cin >> N;
 
    for (int i = 1; i <= N; i++) {
        if (i >= 10 && i <= 99) {
            continue;
        } else if (i >= 1000 && i <= 9999) {
            continue;
        } else if (i >= 100000 && i <= 999999) {
            continue;
        } 
 
        num++;
 
    }
 
    cout << num;
 
    return 0;
}