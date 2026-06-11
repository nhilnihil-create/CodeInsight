#include <iostream>
#include <cstddef>
#include <string>
using ll = long long;

ll n;
std::string s, s2;
char t[4];
char p;
ll ans;

int main() {
    std::cin >> n;
    std::cin >> s;
    for (int i = 0; i < 1000; i++) {
        bool torf = true;
        std::snprintf(t, 4, "%03d", i);
        s2 = t;
        long long int pos = -1;
        for (int j = 0; j < 3; j++) {
            pos = s.find(s2[j], pos+1);
            if (pos == std::string::npos) {
                torf = false;
                break;
            }
        }
        if (torf)
            ans++;
    }
    std::cout << ans << std::endl;
}