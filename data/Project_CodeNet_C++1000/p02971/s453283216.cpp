#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void) {
    int n;
    cin >> n;
    vector<int> s(n), t(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        t[i] = s[i];
    }
    sort(t.begin(), t.end());
    for (int i = 0; i < n; i++) {
        if(s[i]!=t[n-1]){
            cout << t[n - 1] << endl;
        }else
            cout << t[n - 2] << endl;
    }
    return 0;
}