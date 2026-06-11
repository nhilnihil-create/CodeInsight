#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int cnt = 0;
    string W, T, Tlow;

    cin >> W;
    transform(W.begin(), W.end(), W.begin(), ::tolower);
    do {
        cin >> T;
        Tlow = T;
        transform(Tlow.begin(), Tlow.end(), Tlow.begin(), ::tolower);
        if(!(Tlow.compare(W))) ++cnt;
    } while(T.compare("END_OF_TEXT"));
    cout << cnt << endl;

    return 0;
}