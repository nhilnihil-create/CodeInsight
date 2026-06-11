#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

void YesNo(bool x) {
    cout << (x ? "Yes" : "No") << endl;
}

int main() {
    int n, d;
    cin >> n >> d;
    d = d * 2 + 1;
    cout<<(n+d-1)/d<<endl;
    return 0;
}