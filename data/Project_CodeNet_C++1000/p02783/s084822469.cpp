#include <bits/stdc++.h>
using namespace std;

int main () {
    int H,A;
    int count = 0;
    cin >> H >> A;

    while(true){
        H -= A;
        count++;
        if (H <= 0) break;
    }
    cout << count << endl;
}