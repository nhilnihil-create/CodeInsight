#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int h, w, num;
    int tmp;
    cin >> h >> w >> num;

    if (h >= w){
        tmp = num / h;
        if (num % h != 0) tmp++;
        cout << tmp;
    } else {
        tmp = num / w;
        if (num % w != 0) tmp++;
        cout << tmp;
    }
}