#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct task {
    int a;
    int b;
    bool operator<(const task& right) const {
        return b < right.b; 
    }
};
int main() {
    int n;
    cin >> n;
    vector<task> v;
    for (int i=0; i<n; i++) {
        task t;
        cin >> t.a >> t.b;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    int sumA = 0;
    for (int i=0; i<n; i++) {
        sumA += v[i].a;
        if (sumA > v[i].b) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}