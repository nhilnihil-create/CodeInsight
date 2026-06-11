#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int res{0};
    for (size_t i = 0; i < s.size() - 2; ++i) {
        if (s.substr(i, 3) == "ABC") {
            res++;
        }
    }

    cout << res << "\n";
}