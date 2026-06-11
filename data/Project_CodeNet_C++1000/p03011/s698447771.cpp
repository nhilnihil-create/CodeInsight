#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<int> V(3, 0);
    for (int i = 0; i < 3; i++) cin >> V[i];
    sort(V.begin(), V.end());
    printf("%d\n", V[0] + V[1]);
}