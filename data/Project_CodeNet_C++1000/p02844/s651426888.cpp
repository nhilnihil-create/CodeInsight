#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;
typedef long long ll;

int main() {
    int N;
    string S;
    cin >> N;
    cin >> S;
    int ans;
    for(int pin = 0; pin <= 999; pin++) {
        stringstream ss;
        ss << setw(3) << setfill('0') << pin;
        int j = 0;
        for(int i = 0; i < N; i++) {
            if(S[i] == ss.str()[j]) {
                j++;
                if(j == 3) break;
            }
        }
        if(j == 3) ans++;
    }
    cout << ans << endl;
    return 0;
}