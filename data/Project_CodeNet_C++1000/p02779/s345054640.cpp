#include <iostream>
#include <set>

int main() {
    std::set<int> st;
    bool f=true;
    int n; std::cin >> n;
    for(int i=0; i<n; ++i) {
        int a; std::cin >> a;
        if (st.find(a) != st.end())
            f=false;
        st.insert(a);
    }
    std::cout << (f ? "YES" : "NO") << std::endl;
    return 0;
}