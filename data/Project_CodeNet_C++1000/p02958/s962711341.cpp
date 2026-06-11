#include <iostream>

int main() {
    using namespace std;
    int n;
    cin >> n;
    int given, cnt;
    cnt = 0;
    for (int i=1; i<=n; i++){
        cin >> given;
        if (given != i) cnt++;
    }
    if (cnt == 2 || cnt == 0) cout << "YES";
    else cout << "NO";
}