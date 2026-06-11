#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, k, r, s, p;
    cin >> n >> k >> r >> s >> p;
    string t;
    cin >> t;
    for (int i = k; i < n; i++) {
        if (t[i] == t[i-k]) t[i] = 'a';
    }
    int numr, nums, nump;
    numr = 0;
    nums = 0;
    nump = 0;
    for (int i = 0; i < n; i++) {
        if (t[i] == 'r') numr++;
            else if (t[i] == 's') nums++;
                else if (t[i] == 'p') nump++;
    }
    int ans = numr*p + nums*r + nump*s;
	cout << ans << endl;
}