#ifdef _MSC_VER
#include <__msvc_all_public_headers.hpp>
#undef min
#undef max
#else
#define NDEBUG
#include <bits/stdc++.h>
#endif

using namespace std;
using large = long long;

int main() {
    auto s = string{};
    cin >> s;
    cout << s.substr(0, 3);
    return 0;
}
