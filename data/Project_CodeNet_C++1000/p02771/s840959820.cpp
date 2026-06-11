#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
int main() {
    int a, b, c; cin >> a >> b >> c;
    set<int> S;
    S.insert(a); S.insert(b); S.insert(c);
    if (S.size() == 2) printf("%s\n", "Yes");
    else printf("%s\n", "No");
}
