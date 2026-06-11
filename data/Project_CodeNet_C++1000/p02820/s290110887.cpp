#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    int r, s, p;
    string t;
    cin >> r >> s >> p;
    cin >> t;
    char prevChar[k];
    for (int i=0; i<k; i++) {
        prevChar[i] = 'a';
    }
    int point = 0;
    for (int i=0; i<n; i++) {
        if (t[i] != prevChar[i%k]) {
            if (t[i] == 'r') {
                point += p;
            } else if (t[i] == 's') {
                point += r;
            } else if (t[i] == 'p') {
                point += s;
            }
            prevChar[i%k] = t[i];
        } else {
            //同じものが2回続いた場合、その次はどの手を選ぶこともできる
            prevChar[i%k] = 'a';
        }
    }
    cout << point << endl;
}