#include <iostream>
#include <string>

using namespace std;

int main() {
    string t;   int l; cin >> l >> t;
    int ans = 0;
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                bool flag = false;
                int l = 0;
                for (; l < t.length(); l++) {
                    if (t[l]-'0' == i) {
                        flag = true;
                        l++;
                        break;
                    }
                }
                
                if (flag == false)
                    break;
                flag = false;
                for (; l < t.length(); l++) {
                    if (t[l]-'0' == j){
                        flag = true;
                        l++;
                        break;
                    }
                }
                if (flag == false)
                    break;
                flag = false;
                for (; l < t.length(); l++) {
                    if (t[l]-'0' == k) {
                        flag = true;
                        l++;
                        break;
                    }
                }
                if (flag)
                    ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}