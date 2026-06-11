#include <iostream>
using namespace std;

int main(void) {
    int n, p1 = 0, p2 = 0;
    string s1, s2;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s1 >> s2;
        if (s1 == s2) {
            p1++;
            p2++;
        }
        else if (s1 > s2) p1 += 3;
        else p2 += 3;
    }
    cout << p1 << " " << p2 << endl;
    return 0;
}