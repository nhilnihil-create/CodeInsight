#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >>n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >>h.at(i);
    string ret = "Yes";
    for (int i = n-1; i > 0; i--) {
        if (h.at(i)>=h.at(i-1)) {
            //ok
        }
        else if (h.at(i)>=h.at(i-1)-1) {
            h.at(i-1)--;
        }
        else {
            ret = "No";
            break;
        }
    }
    cout << ret << endl;
    return 0;
}