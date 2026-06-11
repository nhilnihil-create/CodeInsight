#include <iostream>
#include <vector>


using ll = long long;
ll r_count, g_count, b_count;
char ch;
int n;
std::string s;

int main() {
    std::cin >> n >> s;
    for (int i = 0; i < n; i++) {
        ch = s[i];
        if (ch == 'R') {
            r_count++;
        }
        else if (ch == 'G') {
            g_count++;
        }
        else {
            b_count++;
        }
    }
    ll num = r_count * g_count * b_count;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int p = j - i;
            int k = j + p;
            if (i == j)
                continue;
            if (k >= n) {
                continue;
            }
            if (s[i] != s[j] && s[j] != s[k] && s[i] != s[k]) {
                num--;
            } 
        }
    }
    std::cout << num << std::endl;
}