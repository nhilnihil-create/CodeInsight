#include <bits/stdc++.h>
//https://qiita.com/ysuzuki19/items/d89057d65284ba1a16ac
#define debug(var)                  \
    do {                            \
        std::cout << #var << " : "; \
        view(var);                  \
    } while (0)
template <typename T>
void view(T e) { std::cout << e << std::endl; }

template <typename T>
void view(const std::vector<T>& v) {
    for (const auto& e : v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void view(const std::vector<std::vector<T>>& vv) {
    for (const auto& v : vv) {
        view(v);
    }
}

using namespace std;
//yosupo
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

int main() {
    int X;
    cin >> X;
    if (X < 600)
        cout << 8 << endl;
    else if (X < 800)
        cout << 7 << endl;
    else if (X < 1000)
        cout << 6 << endl;
    else if (X < 1200)
        cout << 5 << endl;
    else if (X < 1400)
        cout << 4 << endl;
    else if (X < 1600)
        cout << 3 << endl;
    else if (X < 1800)
        cout << 2 << endl;
    else
        cout << 1 << endl;
    return 0;
}