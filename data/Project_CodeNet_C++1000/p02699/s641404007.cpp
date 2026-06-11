#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int s, w;
    cin >> s >> w;

    if (w >= s) {
        cout << "unsafe" << endl;
    }else{
        cout << "safe" << endl;
    }
    return 0;
}
