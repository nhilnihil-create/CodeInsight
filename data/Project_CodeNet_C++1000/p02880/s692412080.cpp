#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    string ans = "No";
    for(int i = 0; i <= 9; i++) {
        for(int j = 0; j <= 9; j++) {
            if(N == i*j) {
                ans = "Yes";
            }
        }
    }
    cout << ans << endl;
}