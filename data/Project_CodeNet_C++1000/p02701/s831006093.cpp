#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
private:
    int N;
    unordered_set<string> str_set;
public:
    void load() {
        cin >> N;
        string s;
        for (int i = 0; i < N; ++i) {
            cin >> s;
            str_set.insert(s);
        }
    }

    size_t solve() {
        return str_set.size();
    }
};

int main() {
    Solution sol;
    sol.load();
    cout << sol.solve() << endl;
}