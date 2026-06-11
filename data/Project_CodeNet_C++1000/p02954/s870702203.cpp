#include <iostream>
#include <vector>
using namespace std;
const int N = 20;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    int doubling[N][n];
    for(int i = 0; i < n; i++) {
        if(s[i] == 'R') doubling[0][i] = i + 1;
        if(s[i] == 'L') doubling[0][i] = i - 1;
    }

    for(int i = 0; i < N - 1; i++) {
        for(int j = 0; j < n; j++) {
            doubling[i + 1][j] = doubling[i][doubling[i][j]];
        }
    } 

    int ans[n] = {};
    for(int i = 0; i < n; i++) {
        ans[doubling[N - 1][i]]++;
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    
    return 0;
}