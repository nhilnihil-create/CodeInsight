#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
  	string s;
    cin >> n >> s;
    if (n < 3200) {
        cout << "red";
    } else {
        cout << s;
    }
}