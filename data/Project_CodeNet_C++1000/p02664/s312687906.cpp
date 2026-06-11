typedef long long ll;
typedef long double ld;
#include <bits/stdc++.h>
using namespace std;

int main() {
    string t;
    std::cin >> t;
    for (int i = 0; i < t.size(); i++) {
        if(t[i]=='?')t[i]='D';
    }
    std::cout << t << std::endl;
}
