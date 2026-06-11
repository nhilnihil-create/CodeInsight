#include <iostream>
#include <set>

using namespace std;

int main() {

    set<string> s;
    size_t N;
    cin >> N;
    for (size_t i = 0; i < N; ++i) {
        string str;
        cin >> str;
        s.insert(str);
    }
    cout << s.size();
    return 0;
}