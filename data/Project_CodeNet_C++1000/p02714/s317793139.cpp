#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    string s;
    long long ans = 0;
    long long count = 0;
    long long r, g, b;
    r = g = b = 0;
    cin >> N  >> s;
    for (int i = 0; i < N; i++) {
        if (s[i] == 'R') {
            r++;
        }else if (s[i] == 'G'){
            g++;
        }else if (s[i] == 'B'){
            b++;
        }
    }
    for (int i = 1; i <= N/2; i++){
        for (int j = 0; j + 2*i < N; j++) {
            if ((s[j] != s[j+i]) && (s[j+2*i] != s[j+i]) && (s[j] != s[j+2*i])) {
                count ++;
            }
        }
    }
    cout << r*g*b - count << endl;

}
