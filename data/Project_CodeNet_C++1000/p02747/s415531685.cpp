#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using str = string;
using ll = long long;
using vi = vector<int>;
using vii = vector<vi>;

int main() {
    str S;
    cin >> S;
    int n = S.size();
    str ans;
    for(int i = 1; i <=5; i++) {
        ans += "hi";
        if(ans == S) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}